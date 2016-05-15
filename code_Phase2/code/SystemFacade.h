#pragma once

#include "Application\MyApplication.h"
#include <App Logic\LawManager.h>
#include "App Logic/DatabaseManager.h"

class SystemFacade
{
public:
	SystemFacade();
	~SystemFacade();

	bool Init();

private:
	MyApplication a2;
	DatabaseManager m_dbHelper;
};

