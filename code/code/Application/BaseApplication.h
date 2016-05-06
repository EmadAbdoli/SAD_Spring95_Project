#pragma once

#include "../pch.h"

class BaseApplication
{
public:

	BaseApplication(bool setGlobal);

	static BaseApplication *Get();
	virtual void AddEventListener(unsigned int eventType, fastdelegate::FastDelegate1<std::shared_ptr<IEvent> > eventHandler) = 0;
	virtual void RemoveEventListener(unsigned int eventType, fastdelegate::FastDelegate1<std::shared_ptr<IEvent> > eventHandler) = 0;
	virtual void SendEvent(std::shared_ptr<IEvent>) = 0;

	virtual ~BaseApplication() {}
};

