#include "MyApplication.h"
#include "console.h"


using namespace std;
using namespace fastdelegate;


MyApplication::MyApplication()
	: BaseApplication(true)
{
#if defined(_DEBUG)
	RedirectIOToConsole();
#endif

	m_mainWindow.show();
	m_mainWindow.Init();
}


MyApplication::~MyApplication()
{
}


void MyApplication::AddEventListener(unsigned int eventType, FastDelegate1<shared_ptr<IEvent> > eventHandler)
{
	m_eventManager.Register(eventType, eventHandler);
}

void MyApplication::RemoveEventListener(unsigned int eventType, FastDelegate1<shared_ptr<IEvent> > eventHandler)
{
	m_eventManager.Remove(eventType, eventHandler);
}

void MyApplication::SendEvent(shared_ptr<IEvent> evt)
{
	m_eventManager.Fire(evt);
}

