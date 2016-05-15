#include "LawManager.h"
#include "../Event Manager/Events.h"
#include "Constraints.h"
#include "../Application/BaseApplication.h"


using namespace std;
using namespace fastdelegate;


shared_ptr<LawManager> LawManager::m_singletonInstance = nullptr;


LawManager::LawManager()
	: m_currConstraint(nullptr), m_isFirstConstraint(true), m_xml("App logic/testLaws.xml")
	, m_loading(false)
{
	RegisterListeners();
	LoadFromDisk();
}


LawManager::~LawManager()
{
}

shared_ptr<LawManager> LawManager::Get()
{
	if (!m_singletonInstance)
		m_singletonInstance.reset(new LawManager);

	return m_singletonInstance;
}

void LawManager::RegisterListeners()
{
	FastDelegate1<shared_ptr<IEvent>> dlg = MakeDelegate(this, &LawManager::NewDateConstraint);
	BaseApplication::Get()->AddEventListener(0xdabb77e1, dlg);

	FastDelegate1<shared_ptr<IEvent>> dlg2 = MakeDelegate(this, &LawManager::NewProductConstraint);
	BaseApplication::Get()->AddEventListener(0xcb1642fe, dlg2);

	FastDelegate1<shared_ptr<IEvent>> dlg3 = MakeDelegate(this, &LawManager::NewArrivalConstraint);
	BaseApplication::Get()->AddEventListener(0xed605f8d, dlg3);

	FastDelegate1<shared_ptr<IEvent>> dlg4 = MakeDelegate(this, &LawManager::NewValueConstraint);
	BaseApplication::Get()->AddEventListener(0x2f737ecb, dlg4);

	FastDelegate1<shared_ptr<IEvent>> dlg5 = MakeDelegate(this, &LawManager::NewCountryConstraint);
	BaseApplication::Get()->AddEventListener(0x81e9c224, dlg5);

	FastDelegate1<shared_ptr<IEvent>> dlg6 = MakeDelegate(this, &LawManager::CreateLaw);
	BaseApplication::Get()->AddEventListener(0xf79c8a7, dlg6);
	
	FastDelegate1<shared_ptr<IEvent>> dlg7 = MakeDelegate(this, &LawManager::CheckDeclaration);
	BaseApplication::Get()->AddEventListener(0xb2b80297, dlg7);

	FastDelegate1<shared_ptr<IEvent>> dlg8 = MakeDelegate(this, &LawManager::NewCompanyConstraint);
	BaseApplication::Get()->AddEventListener(0xcd20ea06, dlg8);
}

void LawManager::LoadFromDisk()
{
	m_loading = true;

	m_xml.Init();

	m_loading = false;
}

void LawManager::CreateLaw(shared_ptr<IEvent> eventPtr)
{
	shared_ptr<Event_Create_Law> evt = static_pointer_cast<Event_Create_Law>(eventPtr);

	m_lawTable[evt->GetLawName()] = Law(m_currConstraint, evt->GetCertificates());

	shared_ptr<Event_UI_Law_Loaded> evt2(make_shared<Event_UI_Law_Loaded>(m_currConstraint->toString(), evt->GetLawName()));
	BaseApplication::Get()->SendEvent(evt2);

	m_currConstraint.reset();
	m_isFirstConstraint = true;

	if (!m_loading) 
	{
		m_xml.Save(XML_Helper::CERTIFICATE, eventPtr);
		m_xml.Finalize(evt->GetLawName().c_str());
	}
}

void LawManager::CheckDeclaration(std::shared_ptr<IEvent> evt)
{
	shared_ptr<Event_CheckWithLaws> evtPtr = static_pointer_cast<Event_CheckWithLaws>(evt);

	vector<pair<string, forward_list<string>>> certVec;
	bool lawApplies = false;

	for (auto &law : m_lawTable) 
	{
		forward_list<string> cl;

		if (law.second.cons->Validate(evtPtr->GetDecl()))
		{
			lawApplies = true;

			for (auto &cer : law.second.certificates)
			{
				cl.push_front(cer);
			}
		}
		if (lawApplies) 
		{
			certVec.push_back(make_pair(law.first, cl));
			lawApplies = false;
		}
	}

	shared_ptr<Event_UI_Required_Certificates> evt2(make_shared<Event_UI_Required_Certificates>(certVec));
	BaseApplication::Get()->SendEvent(evt2);
}

void LawManager::NewDateConstraint(shared_ptr<IEvent> evt)
{
	shared_ptr<Event_Constraint_Date> dateEvent = static_pointer_cast<Event_Constraint_Date>(evt);

	QDate s, e;
	dateEvent->GetDate(s, e);

	if (m_isFirstConstraint)
	{
		m_isFirstConstraint = false;

		shared_ptr<DateConstraint> dc(new DateConstraint(s, e));
		m_currConstraint = dc;
	}
	else
	{
		shared_ptr<ConstraintDecorator<DateConstraint> > df(new ConstraintDecorator<DateConstraint>(m_currConstraint, 
			new DateConstraint(s, e)));
		m_currConstraint = df;
	}

	if (!m_loading)
	{
		shared_ptr<IEvent> uiEvt(make_shared<Event_UI_Update_Law_Desc>(m_currConstraint->toString()));
		BaseApplication::Get()->SendEvent(uiEvt);

		m_xml.Save(XML_Helper::DATE, evt);
	}
}

void LawManager::NewProductConstraint(std::shared_ptr<IEvent> evt)
{
	shared_ptr<Event_Constraint_Product> strEvent = static_pointer_cast<Event_Constraint_Product>(evt);

	if (m_isFirstConstraint)
	{
		m_isFirstConstraint = false;
		shared_ptr<ProductConstraint> pc(new ProductConstraint(strEvent->GetProductNames()));
		m_currConstraint = pc;
	}
	else
	{
		shared_ptr<ConstraintDecorator<ProductConstraint>> pd(new ConstraintDecorator<ProductConstraint>(m_currConstraint, 
			new ProductConstraint(strEvent->GetProductNames())));

		m_currConstraint = pd;
	}

	if (!m_loading)
	{
		shared_ptr<IEvent> uiEvt(make_shared<Event_UI_Update_Law_Desc>(m_currConstraint->toString()));
		BaseApplication::Get()->SendEvent(uiEvt);

		m_xml.Save(XML_Helper::PRODUCT, evt);
	}
}

void LawManager::NewCompanyConstraint(std::shared_ptr<IEvent> evt)
{
	shared_ptr<Event_Constraint_Company> strEvent = static_pointer_cast<Event_Constraint_Company>(evt);

	if (m_isFirstConstraint)
	{
		m_isFirstConstraint = false;
		shared_ptr<CompanyConstraint> pc(new CompanyConstraint(strEvent->GetCompanies()));
		m_currConstraint = pc;
	}
	else
	{
		shared_ptr<ConstraintDecorator<CompanyConstraint>> pd(new ConstraintDecorator<CompanyConstraint>(m_currConstraint, 
			new CompanyConstraint(strEvent->GetCompanies())));
		m_currConstraint = pd;
	}

	if (!m_loading)
	{
		shared_ptr<IEvent> uiEvt(make_shared<Event_UI_Update_Law_Desc>(m_currConstraint->toString()));
		BaseApplication::Get()->SendEvent(uiEvt);

		m_xml.Save(XML_Helper::COMPANY, evt);
	}
}

void LawManager::NewCountryConstraint(shared_ptr<IEvent> evt)
{
	shared_ptr<Event_Constraint_Country> strEvent = static_pointer_cast<Event_Constraint_Country>(evt);

	if (m_isFirstConstraint)
	{
		m_isFirstConstraint = false;
		shared_ptr<CountryConstraint> pc(new CountryConstraint(strEvent->GetCountries()));
		m_currConstraint = pc;
	}
	else
	{
		shared_ptr<ConstraintDecorator<CountryConstraint>> pd(new ConstraintDecorator<CountryConstraint>(m_currConstraint, 
			new CountryConstraint(strEvent->GetCountries())));
		m_currConstraint = pd;
	}

	if (!m_loading)
	{
		shared_ptr<IEvent> uiEvt(make_shared<Event_UI_Update_Law_Desc>(m_currConstraint->toString()));
		BaseApplication::Get()->SendEvent(uiEvt);

		m_xml.Save(XML_Helper::COUNTRY, evt);
	}
}

void LawManager::NewArrivalConstraint(shared_ptr<IEvent> evt)
{
	shared_ptr<Event_Constraint_Arrival> strEvent = static_pointer_cast<Event_Constraint_Arrival>(evt);

	if (m_isFirstConstraint)
	{
		m_isFirstConstraint = false;
		shared_ptr<ArrivalConstraint> pc(new ArrivalConstraint(ArrivalMethod(string(strEvent->GetArrivalMethod()))));
		m_currConstraint = pc;
	}
	else
	{
		shared_ptr<ConstraintDecorator<ArrivalConstraint>> pd(new ConstraintDecorator<ArrivalConstraint>(m_currConstraint,
			new ArrivalConstraint(ArrivalMethod(string(strEvent->GetArrivalMethod())))));
		m_currConstraint = pd;
	}

	if (!m_loading)
	{
		shared_ptr<IEvent> uiEvt(make_shared<Event_UI_Update_Law_Desc>(m_currConstraint->toString()));
		BaseApplication::Get()->SendEvent(uiEvt);

		m_xml.Save(XML_Helper::ARRIVAL, evt);
	}
}

void LawManager::NewValueConstraint(shared_ptr<IEvent> evt)
{
	shared_ptr<Event_Constraint_Value> strEvent = static_pointer_cast<Event_Constraint_Value>(evt);

	if (m_isFirstConstraint)
	{
		m_isFirstConstraint = false;
		shared_ptr<ValueConstraint> pc(new ValueConstraint(strEvent->GetMin(), strEvent->GetMax(), strEvent->IsUnit()));
		m_currConstraint = pc;
	}
	else
	{
		shared_ptr<ConstraintDecorator<ValueConstraint>> pd(new ConstraintDecorator<ValueConstraint>(m_currConstraint,
			new ValueConstraint(strEvent->GetMin(), strEvent->GetMax(), strEvent->IsUnit())));
		m_currConstraint = pd;
	}

	if (!m_loading)
	{
		shared_ptr<IEvent> uiEvt(make_shared<Event_UI_Update_Law_Desc>(m_currConstraint->toString()));
		BaseApplication::Get()->SendEvent(uiEvt);

		m_xml.Save(strEvent->IsUnit() ? XML_Helper::UNIT_VALUE : XML_Helper::TOTAL_VALUE, evt);
	}
}