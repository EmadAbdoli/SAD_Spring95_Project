#include "../pch.h"
#include "XML_Helper.h"
#include "../Event Manager/Events.h"
#include "../Application/BaseApplication.h"

using namespace std;
using namespace tinyxml2;


static fastdelegate::FastDelegate1<XMLElement *> funcPtr[8];


XML_Helper::XML_Helper(const char *fn)
	: m_filename(fn)
{
	funcPtr[0] = fastdelegate::MakeDelegate(this, &XML_Helper::LoadProduct);
	funcPtr[1] = fastdelegate::MakeDelegate(this, &XML_Helper::LoadCompany);
	funcPtr[2] = fastdelegate::MakeDelegate(this, &XML_Helper::LoadDate);
	funcPtr[3] = fastdelegate::MakeDelegate(this, &XML_Helper::LoadCountry);
	funcPtr[4] = fastdelegate::MakeDelegate(this, &XML_Helper::LoadArrival);
	funcPtr[5] = fastdelegate::MakeDelegate(this, &XML_Helper::LoadUnitValue);
	funcPtr[6] = fastdelegate::MakeDelegate(this, &XML_Helper::LoadTotalValue);
	funcPtr[7] = fastdelegate::MakeDelegate(this, &XML_Helper::LoadCertificate);
}


XML_Helper::~XML_Helper()
{
	DeleteFileA(m_tempFile.c_str());
}

bool XML_Helper::Init()
{
	if (!CreateTemp())
		return false;

	if (!Load())
		return false;

	return true;
}

bool XML_Helper::CreateTemp()
{
	char filename[128];

	if (!GetTempFileNameA(".", 0, 0, filename))
		return false;

	HANDLE hTempFile = CreateFileA(filename, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, nullptr, CREATE_ALWAYS,
		FILE_ATTRIBUTE_NORMAL, 0);

	if (hTempFile == INVALID_HANDLE_VALUE)
	{
		LOG(to_string(GetLastError()));
		return false;
	}

	if (!CopyFileA("App Logic/testlaws.xml", filename, false))
	{
		LOG(to_string(GetLastError()));
		return false;
	}

	CloseHandle(hTempFile);

	m_tempFile = filename;

	return true;
}

bool XML_Helper::Load()
{
	if (m_doc.LoadFile(m_tempFile.c_str()))
	{
		LOG("error opening law xml.\n");
		return false;
	}

	XMLElement *root = m_doc.FirstChildElement();

	for (XMLElement *lawNode = root->FirstChildElement(); lawNode != nullptr; lawNode = lawNode->NextSiblingElement())
	{
		string name = lawNode->Attribute("name");

		int i = 0;
		for (XMLElement *constraintNode = lawNode->FirstChildElement(); constraintNode != nullptr;
			constraintNode = constraintNode->NextSiblingElement())
			funcPtr[i++](constraintNode);

		shared_ptr<IEvent> evt(make_shared<Event_Create_Law>(name, m_currCertificates));
		BaseApplication::Get()->SendEvent(evt);

		m_currCertificates.clear();
	}

	return true;
}

void XML_Helper::LoadProduct(XMLElement *elem)
{
	vector<string> prodVec;

	if (elem->NoChildren())
		return;

	for (XMLElement *productNode = elem->FirstChildElement(); productNode != nullptr;
		productNode = productNode->NextSiblingElement())
		prodVec.push_back(productNode->GetText());

	shared_ptr<IEvent> evt(make_shared<Event_Constraint_Product>(prodVec));
	BaseApplication::Get()->SendEvent(evt);
}

void XML_Helper::LoadCompany(XMLElement *elem)
{
	if (elem->NoChildren())
		return;

	vector<string> companyVec;

	for (XMLElement *companyNode = elem->FirstChildElement(); companyNode != nullptr;
		companyNode = companyNode->NextSiblingElement())
		companyVec.push_back(companyNode->GetText());
	
	shared_ptr<IEvent> evt(make_shared<Event_Constraint_Company>(companyVec));
	BaseApplication::Get()->SendEvent(evt);
}

void XML_Helper::LoadDate(XMLElement *elem)
{
	if (elem->NoChildren())
		return;

	QDate start(1, 1, 1);
	QDate end(100000, 1, 1);

	bool change = false;

	XMLElement *currNode = elem->FirstChildElement("Min");

	if (!currNode->NoChildren())
	{
		change = true;
		start = QDate::fromString(elem->FirstChildElement("Min")->GetText(), "dd-MM-yyyy");
	}

	currNode = elem->FirstChildElement("Max");

	if (!currNode->NoChildren())
	{
		change = true;
		end = QDate::fromString(elem->FirstChildElement("Max")->GetText(), "dd-MM-yyyy");
	}

	if (change)
	{
		shared_ptr<IEvent> evt(make_shared<Event_Constraint_Date>(start, end));
		BaseApplication::Get()->SendEvent(evt);
	}
}

void XML_Helper::LoadCountry(XMLElement *elem)
{
	if (elem->NoChildren())
		return;

	vector<string> countryVec;

	for (XMLElement *countryNode = elem->FirstChildElement(); countryNode != nullptr;
		countryNode = countryNode->NextSiblingElement())
		countryVec.push_back(countryNode->GetText());

	shared_ptr<IEvent> evt(make_shared<Event_Constraint_Country>(countryVec));
	BaseApplication::Get()->SendEvent(evt);
}

void XML_Helper::LoadArrival(XMLElement *elem)
{
	if (elem->NoChildren())
		return;

	XMLElement *node = elem->FirstChildElement();

	string a = node->GetText();

	ArrivalMethod am(a);

	shared_ptr<IEvent> evt(make_shared<Event_Constraint_Arrival>(am));
	BaseApplication::Get()->SendEvent(evt);
}

void XML_Helper::LoadUnitValue(XMLElement *elem)
{
	if (elem->NoChildren())
		return;

	int min = INT_MIN;
	int max = INT_MAX;
	bool change = false;

	XMLElement *currNode = elem->FirstChildElement("Min");

	if (!currNode->NoChildren())
	{
		change = true;
		min = stoi(currNode->GetText());
	}

	currNode = elem->FirstChildElement("Max");

	if (!currNode->NoChildren())
	{
		change = true;
		max = stoi(currNode->GetText());
	}
	
	if (change)
	{
		shared_ptr<IEvent> evt(make_shared<Event_Constraint_Value>(min, max, true));
		BaseApplication::Get()->SendEvent(evt);
	}
}

void XML_Helper::LoadTotalValue(XMLElement *elem)
{
	if (elem->NoChildren())
		return;

	int min = INT_MIN;
	int max = INT_MAX;
	bool change = false;

	XMLElement *currNode = elem->FirstChildElement("Min");

	if (!currNode->NoChildren())
	{
		change = true;
		min = stoi(currNode->GetText());
	}

	currNode = elem->FirstChildElement("Max");

	if (!currNode->NoChildren())
	{
		change = true;
		max = stoi(currNode->GetText());
	}

	if (change)
	{
		shared_ptr<IEvent> evt(make_shared<Event_Constraint_Value>(min, max, false));
		BaseApplication::Get()->SendEvent(evt);
	}
}

void XML_Helper::LoadCertificate(tinyxml2::XMLElement *elem)
{
	for (XMLElement *certificateNode = elem->FirstChildElement(); certificateNode != nullptr;
		certificateNode = certificateNode->NextSiblingElement())
		m_currCertificates.push_back(certificateNode->GetText());
}

void XML_Helper::Save(ITEM i, std::shared_ptr<IEvent> e)
{
	shared_ptr<Event_Constraint_Product> evt = static_pointer_cast<Event_Constraint_Product>(e);

	XMLElement *root = m_doc.FirstChildElement();

	bool found = false;
	XMLElement *lawNode;

	for (lawNode = root->FirstChildElement(); lawNode != nullptr;
		lawNode = lawNode->NextSiblingElement())
	{
		if (string(lawNode->Attribute("name")) == "temp")
		{
			found = true;
			break;
		}
	}

	if (!found)
		lawNode = CreateNewLawNode();

	switch (i)
	{
	case XML_Helper::PRODUCT:
		SaveProduct(lawNode, e);
		break;
	case XML_Helper::COMPANY:
		SaveCompany(lawNode, e);
		break;
	case XML_Helper::DATE:
		SaveDate(lawNode, e);
		break;
	case XML_Helper::UNIT_VALUE:
		SaveUnitValue(lawNode, e);
		break;
	case XML_Helper::TOTAL_VALUE:
		SaveTotalValue(lawNode, e);
		break;
	case XML_Helper::ARRIVAL:
		SaveArrival(lawNode, e);
		break;
	case XML_Helper::COUNTRY:
		SaveCountry(lawNode, e);
		break;
	case XML_Helper::CERTIFICATE:
		SaveCertificate(lawNode, e);
		break;
	}
}

void XML_Helper::Finalize(const char *name)
{
	XMLElement *root = m_doc.FirstChildElement();

	XMLElement *lawNode;
	bool found = false;

	for (lawNode = root->FirstChildElement(); lawNode != nullptr;
		lawNode = lawNode->NextSiblingElement())
	{
		if (string(lawNode->Attribute("name")) == "temp")
		{
			found = true;
			break;
		}
	}

	lawNode->SetAttribute("name", name);

	if (m_doc.SaveFile("App logic/testLaws.xml"))
		LOG("Error saving xml.\n");
}

XMLElement *XML_Helper::CreateNewLawNode()
{
	XMLElement *root = m_doc.FirstChildElement();

	XMLElement *newLaw = m_doc.NewElement("Law");
	newLaw->SetAttribute("name", "temp");
	root->InsertEndChild(newLaw);

	XMLElement *prodCons = m_doc.NewElement("ProductConstraint");
	XMLElement *comCons = m_doc.NewElement("CompanyConstraint");
	XMLElement *dateCons = m_doc.NewElement("DateConstraint");
	XMLElement *countCons = m_doc.NewElement("CountryConstraint");
	XMLElement *arrCons = m_doc.NewElement("ArrivalConstraint");
	XMLElement *valCons = m_doc.NewElement("UnitValueConstraint");
	XMLElement *tvalCons = m_doc.NewElement("TotalValueConstraint");
	XMLElement *cers = m_doc.NewElement("CertificateList");

	newLaw->InsertEndChild(prodCons);
	newLaw->InsertEndChild(comCons);
	newLaw->InsertEndChild(dateCons);
	newLaw->InsertEndChild(countCons);
	newLaw->InsertEndChild(arrCons);
	newLaw->InsertEndChild(valCons);
	newLaw->InsertEndChild(tvalCons);
	newLaw->InsertEndChild(cers);

	return newLaw;
}

void XML_Helper::SaveProduct(XMLElement *lawNode, std::shared_ptr<IEvent> evtPtr)
{
	shared_ptr<Event_Constraint_Product> evt = static_pointer_cast<Event_Constraint_Product>(evtPtr);

	XMLElement *elem = lawNode->FirstChildElement("ProductConstraint");

	for (auto &prod : evt->GetProductNames())
	{
		XMLElement *newElem = m_doc.NewElement("Product");
		newElem->SetText(prod.c_str());

		elem->InsertEndChild(newElem);
	}
}

void XML_Helper::SaveCompany(tinyxml2::XMLElement *lawNode, std::shared_ptr<IEvent> evtPtr)
{
	shared_ptr<Event_Constraint_Company> evt = static_pointer_cast<Event_Constraint_Company>(evtPtr);

	XMLElement *elem = lawNode->FirstChildElement("CompanyConstraint");

	for (auto &com : evt->GetCompanies())
	{
		XMLElement *newElem = m_doc.NewElement("Company");
		newElem->SetText(com.c_str());

		elem->InsertEndChild(newElem);
	}
}

void XML_Helper::SaveDate(XMLElement *lawNode, std::shared_ptr<IEvent> evtPtr)
{
	shared_ptr<Event_Constraint_Date> evt = static_pointer_cast<Event_Constraint_Date>(evtPtr);

	QDate s, e;
	evt->GetDate(s, e);

	XMLElement *elem = lawNode->FirstChildElement("DateConstraint");

	XMLElement *newElem_1 = m_doc.NewElement("Min");
	newElem_1->SetText(s.toString("dd-MM-yyyy").toStdString().c_str());

	elem->InsertEndChild(newElem_1);

	XMLElement *newElem_2 = m_doc.NewElement("Max");
	newElem_2->SetText(e.toString("dd-MM-yyyy").toStdString().c_str());

	elem->InsertEndChild(newElem_2);
}

void XML_Helper::SaveCountry(XMLElement *lawNode, std::shared_ptr<IEvent> evtPtr)
{
	shared_ptr<Event_Constraint_Country> evt = static_pointer_cast<Event_Constraint_Country>(evtPtr);

	XMLElement *elem = lawNode->FirstChildElement("CountryConstraint");

	for (auto &com : evt->GetCountries())
	{
		XMLElement *newElem = m_doc.NewElement("Country");
		newElem->SetText(com.c_str());

		elem->InsertEndChild(newElem);
	}
}

void XML_Helper::SaveArrival(XMLElement *lawNode, std::shared_ptr<IEvent> evtPtr)
{
	shared_ptr<Event_Constraint_Arrival> evt = static_pointer_cast<Event_Constraint_Arrival>(evtPtr);

	XMLElement *elem = lawNode->FirstChildElement("ArrivalConstraint");

	XMLElement *newElem = m_doc.NewElement("Method");
	newElem->SetText(evt->GetArrivalMethod());

	elem->InsertEndChild(newElem);
}

void XML_Helper::SaveUnitValue(XMLElement *lawNode, std::shared_ptr<IEvent> evtPtr)
{
	shared_ptr<Event_Constraint_Value> evt = static_pointer_cast<Event_Constraint_Value>(evtPtr);

	XMLElement *elem = lawNode->FirstChildElement("UnitValueConstraint");

	XMLElement *newElem_1 = m_doc.NewElement("Min");
	newElem_1->SetText(to_string(evt->GetMin()).c_str());

	elem->InsertEndChild(newElem_1);

	XMLElement *newElem_2 = m_doc.NewElement("Max");
	newElem_2->SetText(to_string(evt->GetMax()).c_str());

	elem->InsertEndChild(newElem_2);
}

void XML_Helper::SaveTotalValue(XMLElement *lawNode, std::shared_ptr<IEvent> evtPtr)
{
	shared_ptr<Event_Constraint_Value> evt = static_pointer_cast<Event_Constraint_Value>(evtPtr);

	XMLElement *elem = lawNode->FirstChildElement("TotalValueConstraint");

	XMLElement *newElem_1 = m_doc.NewElement("Min");
	newElem_1->SetText(to_string(evt->GetMin()).c_str());

	elem->InsertEndChild(newElem_1);

	XMLElement *newElem_2 = m_doc.NewElement("Max");
	newElem_2->SetText(to_string(evt->GetMax()).c_str());

	elem->InsertEndChild(newElem_2);
}

void XML_Helper::SaveCertificate(tinyxml2::XMLElement *lawNode, std::shared_ptr<IEvent> evtPtr)
{
	shared_ptr<Event_Create_Law> evt = static_pointer_cast<Event_Create_Law>(evtPtr);

	XMLElement *elem = lawNode->FirstChildElement("CertificateList");

	for (auto &com : evt->GetCertificates())
	{
		XMLElement *newElem = m_doc.NewElement("Certificate");
		newElem->SetText(com.c_str());

		elem->InsertEndChild(newElem);
	}
}

