#include "MyMainWindow.h"
#include <qapplication.h>
#include "../Event Manager/Events.h"
#include "../Application/BaseApplication.h"
#include "ConstraintDialog.h"
#include <qmessagebox.h>


using namespace MyUi;
using namespace std;
using namespace fastdelegate;


MyMainWindow::MyMainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	ui.textEdit_4->setReadOnly(true);
}

MyMainWindow::~MyMainWindow()
{
	delete m_constraintDialog;
}

void MyMainWindow::Init()
{
	InitModalDialogs();
	InitTableWidget();

	SetSignals();
	RegisterListeners();

	statusBar()->showMessage("Please Log In First.");

	ui.pushButton_22->setMinimumWidth(10);
	const QRect &r = ui.pushButton_22->geometry();
	ui.pushButton_22->setGeometry(r.topLeft().x(), r.topLeft().y(), 40, 40);
//	ui.tabWidget->setDisabled(true);
}

void MyMainWindow::InitModalDialogs()
{
	m_constraintDialog = new ConstraintDialog;
}

void MyMainWindow::InitTableWidget()
{
	for (int i = 0; i < ui.tableWidget_2->rowCount(); i++)
		ui.tableWidget_2->setRowHeight(i, 26);
}

void MyMainWindow::SetSignals()
{
	connect(ui.pushButton_17, SIGNAL(clicked()), this, SLOT(NewUser()));
	connect(ui.pushButton_9, SIGNAL(clicked()), this, SLOT(LogIn()));
	connect(ui.listWidget, SIGNAL(currentItemChanged(QListWidgetItem *, QListWidgetItem *)), this, 
		SLOT(ChangeCurrentItem(QListWidgetItem *, QListWidgetItem *)));
	connect(ui.pushButton_19, SIGNAL(clicked()), this, SLOT(NewConstraintDialog()));
	connect(ui.pushButton_2, SIGNAL(clicked()), this, SLOT(NewLaw()));
	connect(ui.pushButton_21, SIGNAL(clicked()), this, SLOT(LoadDeclaration()));
	connect(ui.pushButton_20, SIGNAL(clicked()), this, SLOT(SaveDeclaration()));
	connect(ui.pushButton_22, SIGNAL(clicked()), this, SLOT(AddRow()));
	connect(ui.pushButton_11, SIGNAL(clicked()), this, SLOT(ClearDeclaration()));
	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(CheckWithLaws()));
	connect(ui.pushButton_3, SIGNAL(clicked()), this, SLOT(NewCertificate()));
	connect(ui.pushButton_4, SIGNAL(clicked()), this, SLOT(LoadCertificate()));
	connect(ui.pushButton_5, SIGNAL(clicked()), this, SLOT(UpdateCertificate()));
}

void MyMainWindow::RegisterListeners()
{
	FastDelegate1<shared_ptr<IEvent>> dlg = MakeDelegate(this, &MyMainWindow::PermissionsRetrieved);
	BaseApplication::Get()->AddEventListener(0xd6b3f351, dlg);

	FastDelegate1<shared_ptr<IEvent>> dlg2 = MakeDelegate(this, &MyMainWindow::LawDescUpdated);
	BaseApplication::Get()->AddEventListener(0xae72b644, dlg2);

	FastDelegate1<shared_ptr<IEvent>> dlg3 = MakeDelegate(this, &MyMainWindow::DeclarationRetrieved);
	BaseApplication::Get()->AddEventListener(0xb40d424e, dlg3);

	FastDelegate1<shared_ptr<IEvent>> dlg4 = MakeDelegate(this, &MyMainWindow::ShowSuccessMsg);
	BaseApplication::Get()->AddEventListener(0x7b0d3c8f, dlg4);

	FastDelegate1<shared_ptr<IEvent>> dlg5 = MakeDelegate(this, &MyMainWindow::CertificateLoaded);
	BaseApplication::Get()->AddEventListener(0x6c545269, dlg5);

	FastDelegate1<shared_ptr<IEvent>> dlg6 = MakeDelegate(this, &MyMainWindow::LawLoaded);
	BaseApplication::Get()->AddEventListener(0x9f760d39, dlg6);

	FastDelegate1<shared_ptr<IEvent>> dlg7 = MakeDelegate(this, &MyMainWindow::RequiredCertificatesLoaded);
	BaseApplication::Get()->AddEventListener(0x33ce3a23, dlg7);
}

void MyMainWindow::NewConstraintDialog()
{
	m_constraintDialog->exec();
}

void MyMainWindow::AddRow()
{
	ui.tableWidget_2->insertRow(ui.tableWidget_2->rowCount());
}

void MyMainWindow::ClearDeclaration()
{
	ui.lineEdit_12->clear();
	ui.lineEdit->clear();
	ui.lineEdit_2->clear();
	ui.dateEdit->clear();
	ui.lineEdit_4->clear();
	ui.lineEdit_5->clear();
	ui.comboBox->currentText().clear();
	ui.lineEdit_11->clear();

	ui.tableWidget_2->clearContents();
	ui.tableWidget_2->setRowCount(1);
}

void MyMainWindow::CheckWithLaws()
{
	Declaration dec;
	dec.ID = ui.lineEdit_12->text().toInt();
	dec.SSN = ui.lineEdit->text().toInt();
	dec.Name = ui.lineEdit_2->text().toStdString();
	dec.DeclDate = ui.dateEdit->date();
	dec.TotalValue = 0;
	dec.SourceCountry = ui.lineEdit_5->text().toStdString();
	dec.Arrival = ArrivalMethod(ui.comboBox->currentText().toStdString());
	dec.Count = ui.lineEdit_11->text().toInt();

	vector<Product> prodVec;
	for (int i = 0; i < ui.tableWidget_2->rowCount(); i++)
	{
		Product p;
		p.Name = ui.tableWidget_2->item(i, 0)->text().toStdString();
		p.Company = ui.tableWidget_2->item(i, 1)->text().toStdString();
		p.Weight = ui.tableWidget_2->item(i, 2)->text().toInt();
		p.Count = ui.tableWidget_2->item(i, 3)->text().toInt();
		p.Price = ui.tableWidget_2->item(i, 4)->text().toInt();

		dec.TotalValue += p.Count * p.Price;

		prodVec.push_back(p);
	}

	dec.ProductVec = prodVec;

	shared_ptr<IEvent> evt(make_shared<Event_CheckWithLaws>(dec));
	BaseApplication::Get()->SendEvent(evt);
}

void MyUi::MyMainWindow::NewCertificate()
{
	if (ui.lineEdit_13->text() == "" || ui.lineEdit_15->text() == "" || ui.lineEdit_3->text() == "")
	{
		QMessageBox::critical(this, "Error", "Required fields are not filled.", QMessageBox::Ok);

		return;
	}

	Certificate ccc;
	ccc.Type = ui.comboBox_4->currentText().toStdString();
	ccc.ID = ui.lineEdit_13->text().toInt();
	ccc.Name = ui.lineEdit_15->text().toStdString();
	ccc.IssueDate = ui.dateEdit_2->date();
	ccc.ExpireDate = ui.dateEdit_3->date();
	ccc.MaxValue = ui.lineEdit_3->text().toInt();

	shared_ptr<IEvent> evt(make_shared<Event_DB_New_Certificate>(ccc));
	BaseApplication::Get()->SendEvent(evt);
}

void MyUi::MyMainWindow::LoadCertificate()
{
	if (ui.lineEdit_13->text() == "")
	{
		QMessageBox::critical(this, "Error", "Certificate ID is not specified.", QMessageBox::Ok);

		return;
	}

	shared_ptr<IEvent> evt = make_shared<Event_DB_Load_Certificate>(ui.lineEdit_13->text().toInt(), 
		ui.comboBox_4->currentText().toStdString());
	BaseApplication::Get()->SendEvent(evt);
}

void MyMainWindow::UpdateCertificate()
{
	if (ui.lineEdit_13->text() == "" || ui.lineEdit_14->text() == "")
	{
		QMessageBox::critical(this, "Error", "Certificate ID or Declaration ID is not specified.", QMessageBox::Ok);

		return;
	}

	int cid = ui.lineEdit_13->text().toInt();
	int did = ui.lineEdit_14->text().toInt();
	string type = ui.comboBox_4->currentText().toStdString();

	shared_ptr<IEvent> evt = make_shared<Event_DB_Update_Certificate>(cid, did, type);
	BaseApplication::Get()->SendEvent(evt);
}

void MyMainWindow::ShowSuccessMsg(std::shared_ptr<IEvent> evtPtr)
{
	shared_ptr<Event_UI_Success> evt = static_pointer_cast<Event_UI_Success>(evtPtr);

	statusBar()->showMessage(evt->GetText());
}

void MyMainWindow::CertificateLoaded(std::shared_ptr<IEvent> evtPtr)
{
	shared_ptr<Event_UI_Certificate_Loaded> evt = static_pointer_cast<Event_UI_Certificate_Loaded>(evtPtr);

	const Certificate &c = evt->GetCert();

	ui.lineEdit_13->setText(QString::number(c.ID));
	ui.lineEdit_15->setText(QString::fromStdString(c.Name));
	ui.lineEdit_3->setText(QString::number(c.MaxValue));
	ui.lineEdit_6->setText(QString::fromStdString(c.IssuedBy));
	ui.dateEdit_2->setDate(c.IssueDate);
	ui.dateEdit_3->setDate(c.ExpireDate);
}

void MyMainWindow::LawLoaded(std::shared_ptr<IEvent> evtPtr)
{
	shared_ptr<Event_UI_Law_Loaded> evt = static_pointer_cast<Event_UI_Law_Loaded>(evtPtr);

	m_lawDescs[evt->GetLawName()] = evt->GetDesc();

	ui.listWidget->addItem(evt->GetLawName().c_str());
}

void MyUi::MyMainWindow::RequiredCertificatesLoaded(std::shared_ptr<IEvent> evtPtr)
{
	shared_ptr<Event_UI_Required_Certificates> evt = static_pointer_cast<Event_UI_Required_Certificates>(evtPtr);

	if (evt->GetCertificates().empty()) 
	{
		ui.textEdit->setText("No certificate needed.\n");
		return;
	}

	string s;

	for (auto &law : evt->GetCertificates())
	{
		s += "According to Law '" + law.first + "' You Need Following Certificates : ";
		for (auto & cer : law.second)
		{
			s += cer + ", ";
		}
		s += "\n";
	}

	ui.textEdit->setText(s.c_str());
}

void MyMainWindow::SaveDeclaration()
{
	if (ui.lineEdit_12->text() == "" || ui.lineEdit->text() == "" || ui.lineEdit_2->text() == ""
		|| ui.lineEdit_5->text() == "" || ui.lineEdit_11->text() == "")
	{
		QMessageBox::critical(this, "Error", "Required fields are not filled.", QMessageBox::Ok);
		return;
	}

	Declaration dec;
	dec.ID = ui.lineEdit_12->text().toInt();
	dec.SSN = ui.lineEdit->text().toInt();
	dec.Name = ui.lineEdit_2->text().toStdString();
	dec.DeclDate = ui.dateEdit->date();
//	dec.TotalValue = ui.lineEdit_4->text().toInt();
	dec.SourceCountry = ui.lineEdit_5->text().toStdString();
	dec.Arrival = ArrivalMethod(ui.comboBox->currentText().toStdString());
	dec.Count = ui.lineEdit_11->text().toInt();

	vector<Product> prodVec;
	for (int i = 0; i < ui.tableWidget_2->rowCount(); i++)
	{
		Product p;
		p.Name = ui.tableWidget_2->item(i, 0)->text().toStdString();
		p.Company = ui.tableWidget_2->item(i, 1)->text().toStdString();
		p.Weight = ui.tableWidget_2->item(i, 2)->text().toInt();
		p.Count = ui.tableWidget_2->item(i, 3)->text().toInt();
		p.Price = ui.tableWidget_2->item(i, 4)->text().toInt();

		prodVec.push_back(p);
	}

	dec.ProductVec = prodVec;

	shared_ptr<IEvent> evt(make_shared<Event_DB_New_Declaration>(dec));
	BaseApplication::Get()->SendEvent(evt);
}

void MyMainWindow::LoadDeclaration()
{
	if (ui.lineEdit_12->text() == "")
	{
		QMessageBox::critical(this, "Error", "Declaration ID is not specified.", QMessageBox::Ok);

		return;
	}

	shared_ptr<IEvent> evt = make_shared<Event_DB_Load_Declaration>(ui.lineEdit_12->text().toInt());
	BaseApplication::Get()->SendEvent(evt);
}

void MyMainWindow::NewUser()
{
	QString username = ui.lineEdit_8->text();
	QString password = ui.lineEdit_9->text();

	shared_ptr<IEvent> evt(make_shared<Event_DB_New_User>(username.toStdString(), password.toStdString()));

	BaseApplication::Get()->SendEvent(evt);
}

void MyMainWindow::NewLaw()
{
	string lawName = ui.lineEdit_7->text().toStdString();

	if (lawName == "")
	{
		QMessageBox::critical(this, "Error", "You haven't specified a name.", QMessageBox::Ok);
		return;
	}

	vector<string> certificateVec;

	auto AddIfChecked = [&certificateVec](QCheckBox *c)
	{
		if (c->isChecked())
			certificateVec.push_back(c->text().toStdString());
	};

	AddIfChecked(ui.checkBox);
	AddIfChecked(ui.checkBox_2);
	AddIfChecked(ui.checkBox_3);

	ui.textEdit_4->clear();
	ui.checkBox->setChecked(false);
	ui.checkBox_2->setChecked(false);
	ui.checkBox_3->setChecked(false);
	ui.lineEdit_7->clear();

	shared_ptr<IEvent> evt(make_shared<Event_Create_Law>(lawName, certificateVec));
	BaseApplication::Get()->SendEvent(evt);
}

void MyMainWindow::LogIn()
{
	QString username = ui.lineEdit_23->text();
	QString password = ui.lineEdit_24->text();

	shared_ptr<IEvent> evt(make_shared<Event_DB_Log_In>(username.toStdString(), password.toStdString()));

	BaseApplication::Get()->SendEvent(evt);

	ui.tabWidget->setEnabled(true);
}

void MyMainWindow::ChangeCurrentItem(QListWidgetItem *current, QListWidgetItem *previous)
{
	string &lawDesc = m_lawDescs[current->text().toStdString()];

	ui.textEdit_3->setText(lawDesc.c_str());
}

void MyMainWindow::PermissionsRetrieved(std::shared_ptr<IEvent> eventPtr)
{
	shared_ptr<Event_UI_Permissions_Retrieved> evt = static_pointer_cast<Event_UI_Permissions_Retrieved>(eventPtr);

	auto &permissionVec = evt->GetPermissions();

	string fullPermission;

	for (auto &per : permissionVec)
	{
		stringstream ss;
		ss << "You Have " << per.first << " Permission On Table : " << per.second << endl;

		fullPermission += ss.str();
	}

	ui.textEdit_2->setText(QString(fullPermission.c_str()));

	ui.pushButton_9->setDisabled(true);
	ui.lineEdit_23->setDisabled(true);
	ui.lineEdit_24->setDisabled(true);

	statusBar()->showMessage(QString("Logged in as : " + ui.lineEdit_23->text()));
}

void MyMainWindow::LawDescUpdated(std::shared_ptr<IEvent> eventPtr)
{
	shared_ptr<Event_UI_Update_Law_Desc> evt = static_pointer_cast<Event_UI_Update_Law_Desc>(eventPtr);

	ui.textEdit_4->setPlainText(evt->GetLawDescription().c_str());
}

void MyMainWindow::DeclarationRetrieved(std::shared_ptr<IEvent> eventPtr)
{
	shared_ptr<Event_UI_Declaration_Retrieved> evt = static_pointer_cast<Event_UI_Declaration_Retrieved>(eventPtr);

	auto &dec = evt->GetDecl();
	auto &prods = evt->GetDecl().ProductVec;

	ui.lineEdit_12->setText(QString::number(dec.ID));
	ui.lineEdit->setText(QString::number(dec.SSN));
	ui.lineEdit_2->setText(QString(dec.Name.c_str()));
	ui.dateEdit->setDate(dec.DeclDate);
	ui.lineEdit_4->setText(QString::number(dec.TotalValue));
	ui.lineEdit_5->setText(QString(dec.SourceCountry.c_str()));
	ui.comboBox->setCurrentText(QString(dec.Arrival.toString()));
	ui.lineEdit_11->setText(QString::number(dec.Count));

	ui.tableWidget_2->clearContents();
	ui.tableWidget_2->setRowCount(prods.size());

	int i = 0;
	for (const Product &p : prods)
	{
		ui.tableWidget_2->setItem(i, 0, new QTableWidgetItem(p.Name.c_str()));
		ui.tableWidget_2->setItem(i, 1, new QTableWidgetItem(p.Company.c_str()));
		ui.tableWidget_2->setItem(i, 2, new QTableWidgetItem(QString::number(p.Weight)));
		ui.tableWidget_2->setItem(i, 3, new QTableWidgetItem(QString::number(p.Count)));
		ui.tableWidget_2->setItem(i, 4, new QTableWidgetItem(QString::number(p.Price)));

		i++;
	}
}

