#include "../pch.h"
#include "XML_Helper.h"
#include "../Event Manager/Events.h"
#include "../Application/BaseApplication.h"

using namespace std;
using namespace tinyxml2;


static void(XML_Helper::*funcPtr[5])(XMLElement *);


XML_Helper::XML_Helper(const char *fn)
	: m_filename(fn)
{
	funcPtr[0] = &XML_Helper::LoadProduct;
	funcPtr[1] = &XML_Helper::LoadDate;
	funcPtr[2] = &XML_Helper::LoadCountry;
	funcPtr[3] = &XML_Helper::LoadArrival;
	funcPtr[4] = &XML_Helper::LoadValue;
}


XML_Helper::~XML_Helper()
{
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
	XMLDocument doc;
	if (doc.LoadFile(m_tempFile.c_str()))
	{
		LOG("error opening law xml.\n");
		return false;
	}

	XMLElement *root = doc.FirstChildElement();

	for (XMLElement *lawNode = root->FirstChildElement(); lawNode != nullptr; lawNode = lawNode->NextSiblingElement())
	{
		string name = lawNode->Attribute("name");

		int i = 0;
		for (XMLElement *constraintNode = lawNode->FirstChildElement(); constraintNode != nullptr;
			constraintNode = constraintNode->NextSiblingElement())
			(this->*funcPtr[i++])(constraintNode);

		shared_ptr<IEvent> evt(make_shared<Event_Create_Law>(name));
		BaseApplication::Get()->SendEvent(evt);
	}

	return true;
}

void XML_Helper::LoadProduct(XMLElement *elem)
{
	if (elem->NoChildren())
		return;

	vector<string> prodVec;
	vector<string> companyVec;
	unsigned int min = INT_MAX, max = 0;

	for (XMLElement *productNode = elem->FirstChildElement(); productNode != nullptr;
		productNode = productNode->NextSiblingElement())
	{
		prodVec.push_back(productNode->FirstChildElement("Name")->GetText());
		companyVec.push_back(productNode->FirstChildElement("Company")->GetText());

		XMLElement *valueElem = productNode->FirstChildElement("Value");

		if (!valueElem->FirstChildElement("Min")->NoChildren())
			min = stoi(valueElem->FirstChildElement("Min")->GetText());
		
		if (!valueElem->FirstChildElement("Max")->NoChildren())
			max = stoi(valueElem->FirstChildElement("Max")->GetText());
	}

	shared_ptr<IEvent> evt(make_shared<Event_Constraint_Product>(prodVec, companyVec, min, max));
	BaseApplication::Get()->SendEvent(evt);
}

void XML_Helper::LoadDate(XMLElement *elem)
{
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
	XMLElement *node = elem->FirstChildElement();

	if (node->NoChildren())
		return;

	string a = node->GetText();
	for_each(a.begin(), a.end(), tolower);

	ArrivalMethod am(a);

	shared_ptr<IEvent> evt(make_shared<Event_Constraint_Arrival>(am));
	BaseApplication::Get()->SendEvent(evt);
}

void XML_Helper::LoadValue(XMLElement *elem)
{
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
		shared_ptr<IEvent> evt(make_shared<Event_Constraint_Value>(min, max));
		BaseApplication::Get()->SendEvent(evt);
	}
}

void XML_Helper::Save(ITEM i, std::shared_ptr<IEvent> e)
{
	switch (i)
	{
	case XML_Helper::PRODUCT:
		SaveProduct(e);
		break;
	case XML_Helper::DATE:
		SaveDate(e);
		break;
	case XML_Helper::VALUE:
		SaveValue(e);
		break;
	case XML_Helper::ARRIVAL:
		SaveArrival(e);
		break;
	case XML_Helper::COUNTRY:
		SaveCountry(e);
		break;
	}
}

void XML_Helper::Finalize()
{

}

void XML_Helper::SaveProduct(std::shared_ptr<IEvent> e)
{

}

void XML_Helper::SaveDate(std::shared_ptr<IEvent> e)
{

}

void XML_Helper::SaveCountry(std::shared_ptr<IEvent> e)  
{

}

void XML_Helper::SaveArrival(std::shared_ptr<IEvent> e)
{

}

void XML_Helper::SaveValue(std::shared_ptr<IEvent> e)
{

}