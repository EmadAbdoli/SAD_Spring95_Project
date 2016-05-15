#include "EventManager.h"

using namespace std;
using namespace fastdelegate;


EventManager::EventManager()
{
}


EventManager::~EventManager()
{
}

void EventManager::Register(unsigned int eventType, fastdelegate::FastDelegate1<std::shared_ptr<IEvent> > eventHandler)
{
	auto eventIt = m_EventHandlerMap.find(eventType);

	if (eventIt != m_EventHandlerMap.end())
	{
		auto &dlgList = eventIt->second;

		if (find(dlgList.begin(), dlgList.end(), eventHandler) == dlgList.end())
			dlgList.push_front(eventHandler);
		else
			LOG("attempting to register a delegate more than once.\n");
	}
	else
	{
		forward_list < FastDelegate1<shared_ptr<IEvent> > > dlgList;
		dlgList.push_front(eventHandler);
		m_EventHandlerMap.insert(make_pair(eventType, dlgList));
	}
}

void EventManager::Remove(unsigned int eventType, fastdelegate::FastDelegate1<std::shared_ptr<IEvent> > eventHandler)
{

}

void EventManager::Fire(std::shared_ptr<IEvent> eventPtr)
{
	unsigned int key = eventPtr->GetType();

	auto eventIt = m_EventHandlerMap.find(key);

	if (eventIt != m_EventHandlerMap.end())
	{
		auto &delegateList = eventIt->second;

		for (auto &dlg : delegateList)
			dlg(eventPtr);
	}
	else
		LOG("unknown event was recieved.\n");
}