#pragma once

#include "../pch.h"
#include "../UI/MyMainWindow.h"
#include "../Event Manager/EventManager.h"
#include "BaseApplication.h"


class MyApplication : public BaseApplication
{
public:

	MyApplication();
	~MyApplication();

	void AddEventListener(unsigned int eventType, fastdelegate::FastDelegate1<std::shared_ptr<IEvent> > eventHandler) override;
	void RemoveEventListener(unsigned int eventType, fastdelegate::FastDelegate1<std::shared_ptr<IEvent> > eventHandler) override;
	void SendEvent(std::shared_ptr<IEvent>) override;

private:

	MyApplication(const MyApplication &) = delete;
	MyApplication &operator=(const MyApplication &) = delete;

	EventManager m_eventManager;
	MyUi::MyMainWindow m_mainWindow;
};

