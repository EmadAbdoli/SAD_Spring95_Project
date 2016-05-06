#include "BaseApplication.h"
#include <cassert>

static BaseApplication *g_App = nullptr;


BaseApplication::BaseApplication(bool setGlobal)
{
	if (setGlobal)
	{
		if (!g_App)
			g_App = this;
		else
		{
			LOG("Another application was already set.\n");
			delete g_App;
			g_App = this;
		}
	}
}

BaseApplication *BaseApplication::Get()
{
	assert(g_App);

	return g_App;
}
