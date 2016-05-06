#include "LawManager.h"
#include "../Event Manager/Events.h"
#include "Constraints.h"
#include "../Application/BaseApplication.h"


using namespace std;
using namespace fastdelegate;


shared_ptr<LawManager> LawManager::m_singletonInstance = nullptr;


LawManager::LawManager()
	: m_currConstraint(nullptr), m_isModified(false), m_isFirstConstraint(true), m_xml("App logic/testLaws.xml")
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
}

void LawManager::LoadFromDisk()
{
	m_loading = true;

	m_xml.Init();

	m_loading = false;

//	cout << m_currConstraint->toString() << endl;
}

void LawManager::SaveToDisk()
{
	//if (m_isModified)
		//
}

void LawManager::CreateLaw(shared_ptr<IEvent> eventPtr)
{
	shared_ptr<Event_Create_Law> evt = static_pointer_cast<Event_Create_Law>(eventPtr);

	m_lawTable[evt->GetLawName()] = m_currConstraint;

	m_currConstraint.reset();

	if (!m_loading)
	{
		m_isModified = true;
		m_xml.Finalize();
	}
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
		shared_ptr<DateDecorator> df(new DateDecorator(m_currConstraint, s, e));
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
		shared_ptr<ProductConstraint> pc(new ProductConstraint(strEvent->GetProductNames(), strEvent->GetCompanies()));
		m_currConstraint = pc;
	}
	else
	{
		shared_ptr<ProductDecorator> pd(
			new ProductDecorator(m_currConstraint, strEvent->GetProductNames(), strEvent->GetCompanies()));
		m_currConstraint = pd;
	}

	if (!m_loading)
	{
		shared_ptr<IEvent> uiEvt(make_shared<Event_UI_Update_Law_Desc>(m_currConstraint->toString()));
		BaseApplication::Get()->SendEvent(uiEvt);

		m_xml.Save(XML_Helper::PRODUCT, evt);
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
		shared_ptr<CountryDecorator> pd(
			new CountryDecorator(m_currConstraint, strEvent->GetCountries()));
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
		shared_ptr<ArrivalConstraint> pc(new ArrivalConstraint(strEvent->GetArrivalMethod()));
		m_currConstraint = pc;
	}
	else
	{
		shared_ptr<ArrivalDecorator> pd(
			new ArrivalDecorator(m_currConstraint, strEvent->GetArrivalMethod()));
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
		shared_ptr<ValueConstraint> pc(new ValueConstraint(strEvent->GetMin(), strEvent->GetMax()));
		m_currConstraint = pc;
	}
	else
	{
		shared_ptr<ValueDecorator> pd(
			new ValueDecorator(m_currConstraint, strEvent->GetMin(), strEvent->GetMax()));
		m_currConstraint = pd;
	}

	if (!m_loading)
	{
		shared_ptr<IEvent> uiEvt(make_shared<Event_UI_Update_Law_Desc>(m_currConstraint->toString()));
		BaseApplication::Get()->SendEvent(uiEvt);

		m_xml.Save(XML_Helper::VALUE, evt);
	}
}