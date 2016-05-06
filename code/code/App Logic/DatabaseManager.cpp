#include "../Application/BaseApplication.h"
#include "DatabaseManager.h"
#include "../Event Manager/Events.h"
#include <qsqlerror.h>
#include <qvariant.h>
#include <regex>

using namespace std;
using namespace fastdelegate;

inline string ToMySQLDate(const QDate &d)
{
	stringstream ss;
	ss << "'" << d.year() << "-" << d.month() << "-" << d.day() << "'";

	return ss.str();
}

DatabaseManager::DatabaseManager()
{
	m_dbConnection = QSqlDatabase::addDatabase("QMYSQL", "db_conn");
	m_dbConnection.setHostName("localhost");
	m_dbConnection.setDatabaseName("customs");

	RegisterListeners();
}


DatabaseManager::~DatabaseManager()
{
}

void DatabaseManager::RegisterListeners()
{
	FastDelegate1<shared_ptr<IEvent>> loginDlg = MakeDelegate(this, &DatabaseManager::LogIn);
	FastDelegate1<shared_ptr<IEvent>> newUserDlg = MakeDelegate(this, &DatabaseManager::NewUser);
	FastDelegate1<shared_ptr<IEvent>> newDec = MakeDelegate(this, &DatabaseManager::NewDeclaration);
	FastDelegate1<shared_ptr<IEvent>> loadDec = MakeDelegate(this, &DatabaseManager::LoadDeclaration);

	BaseApplication::Get()->AddEventListener(0x24281fb9, loginDlg);
	BaseApplication::Get()->AddEventListener(0x8d039c59, newUserDlg);
	BaseApplication::Get()->AddEventListener(0x72b54109, newDec);
	BaseApplication::Get()->AddEventListener(0x4cc99623, loadDec);
}

bool DatabaseManager::Execute(QSqlQuery &query, const char *str)
{
	stringstream ss;

	if (!query.exec(str))
	{
		QSqlError err = query.lastError();
		ss << query.executedQuery().toStdString() << " failed with error : " << err.text().toStdString() << endl;
		LOG(ss.str());

		return false;
	}

	return true;
}

void DatabaseManager::LogIn(std::shared_ptr<IEvent> eventPtr)
{
	std::shared_ptr<Event_DB_Log_In> evt = static_pointer_cast<Event_DB_Log_In>(eventPtr);

	m_dbConnection.setUserName(QString(evt->GetUsername().c_str()));
	m_dbConnection.setPassword(QString(evt->GetPassword().c_str()));

	if (!m_dbConnection.open())
	{
		QSqlError err = m_dbConnection.lastError();
		LOG(string("connection failed with error : ") + err.text().toStdString());

		return;
	}

	vector<pair<string, string>> grantVec;

	if (!RetrievePrivilleges(grantVec))
		return;

	shared_ptr<IEvent> guiEvent(make_shared<Event_UI_Permissions_Retrieved>(grantVec));
	BaseApplication::Get()->SendEvent(guiEvent);
}

void DatabaseManager::NewDeclaration(std::shared_ptr<IEvent> eventPtr)
{
	shared_ptr<Event_DB_New_Declaration> evt = static_pointer_cast<Event_DB_New_Declaration>(eventPtr);

	auto &d = evt->GetDecl();
	auto &p = evt->GetProducts();

	QSqlQuery q(m_dbConnection);
	stringstream ss;
	ss << "INSERT INTO Declaration VALUES(" << d.ID << "," << d.SSN << ",'" << d.Name << "'," << ToMySQLDate(d.DeclDate)
		<< "," << 0 << ",'" << d.SourceCountry << "','" << d.Arrival.toString() << "'," << d.Count << ")";

	if (!Execute(q, ss.str().c_str()))
	{
		LOG("Inserting new declaration failed.\n");
		return;
	}

	for (auto &prod : p)
	{
		QSqlQuery q2(m_dbConnection);

		stringstream ss2;

		ss2 << "INSERT INTO Product VALUES(" << d.ID << ",'" << prod.Name << "','" << prod.Company << "'," << prod.Weight
			<< "," << prod.Count << "," << prod.Price << ")";

		if (!Execute(q2, ss2.str().c_str()))
		{
			LOG("Inserting new product failed.\n");
			return;
		}
	}

	shared_ptr<IEvent> evt2(make_shared<Event_UI_Success>("Declaration Saved Successfully."));
	BaseApplication::Get()->SendEvent(evt2);
}

void DatabaseManager::LoadDeclaration(std::shared_ptr<IEvent> eventPtr)
{
	shared_ptr<Event_DB_Load_Declaration> evt = static_pointer_cast<Event_DB_Load_Declaration>(eventPtr);

	QSqlQuery q(m_dbConnection);

	stringstream ss;
	ss << "select * from declaration where id=" << evt->GetID();

	if (!Execute(q, ss.str().c_str()))
	{
		LOG("Failed to load declaration from db.\n");
		return;
	}

	Declaration dec;
	vector<Product> prodVec;

	q.next();

	dec.ID = evt->GetID();
	dec.SSN = q.value(1).toInt();
	dec.Name = q.value(2).toString().toStdString();
	dec.DeclDate = q.value(3).toDate();
	dec.TotalValue = q.value(4).toInt();
	dec.SourceCountry = q.value(5).toString().toStdString();
	dec.Arrival = ArrivalMethod(q.value(6).toString().toStdString());
	dec.Count = q.value(7).toInt();

	QSqlQuery q2(m_dbConnection);
	stringstream ss2;
	ss2 << "select * from product where id=" << evt->GetID();

	if (!Execute(q2, ss2.str().c_str()))
	{
		LOG("Failed to load product info from db.\n");
		return;
	}

	while(q2.next())
	{
		Product p;
		p.Name = q2.value(1).toString().toStdString();
		p.Company = q2.value(2).toString().toStdString();
		p.Weight = q2.value(3).toInt();
		p.Count = q2.value(4).toInt();
		p.Price = q2.value(5).toInt();

		prodVec.push_back(p);
	}

	shared_ptr<IEvent> evt2(make_shared<Event_UI_Declaration_Retrieved>(dec, prodVec));
	BaseApplication::Get()->SendEvent(evt2);
}

void DatabaseManager::NewUser(std::shared_ptr<IEvent> eventPtr)
{
	std::shared_ptr<Event_DB_New_User> evt = static_pointer_cast<Event_DB_New_User>(eventPtr);

	std::stringstream ss;
	ss << "create user '" << evt->GetUsername() << "'" << "@'localhost' identified by '" << evt->GetPassword() << "';";

	QSqlQuery query(m_dbConnection);

	Execute(query, ss.str().c_str());
}

void DatabaseManager::NewPermission(std::shared_ptr<IEvent> eventPtr)
{
	std::shared_ptr<Event_DB_New_Permission> evt = static_pointer_cast<Event_DB_New_Permission>(eventPtr);

	std::stringstream ss;
	ss << "grant " << evt->GetPermissionType() << " on customs." << evt->GetTable() << 
		"to '" << evt->GetUsername() << "'@'localhost'";

	QSqlQuery query(m_dbConnection);

	Execute(query, ss.str().c_str());
}

bool DatabaseManager::RetrievePrivilleges(vector<pair<string, string>> &grantVec)
{
	QSqlQuery query(m_dbConnection);

	if (!Execute(query, "show grants"))
		return false;

	string permission, table;
	
	while (query.next())
	{
		string result = query.value(0).toString().toStdString();
		
		if (!ParseGrants(result, permission, table))
			return false;

		grantVec.push_back(make_pair(permission, table));
	}
	
	return true;
}

bool DatabaseManager::ParseGrants(string &grants ,string &permission, string &table)
{
	regex reg("\\s.*(?=\\sON)");

	smatch match;

	if (!regex_search(grants, match, reg))
	{
		LOG("error parsing grants.\n");
		return false;
	}

	permission = match.str();

	reg = string("\\..*(?=\\sTO)");

	if (!regex_search(grants, match, reg))
	{
		LOG("error parsing grants.\n");
		return false;
	}

	table = (match.str() == ".*" ? "ALL" : match.str().substr(1));

	return true;
}