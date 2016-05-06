#pragma once

#include "../pch.h"
#include "Events.h"

class EventManager
{
public:
	EventManager();
	~EventManager();

	void Register(unsigned int eventType, fastdelegate::FastDelegate1<std::shared_ptr<IEvent> > eventHandler);
	void Remove(unsigned int eventType, fastdelegate::FastDelegate1<std::shared_ptr<IEvent> > eventHandler);
	void Fire(std::shared_ptr<IEvent> eventPtr);

private:
	std::map<unsigned int, std::forward_list < fastdelegate::FastDelegate1<std::shared_ptr<IEvent> > > > m_EventHandlerMap;
};

