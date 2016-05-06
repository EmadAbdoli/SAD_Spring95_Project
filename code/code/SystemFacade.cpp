#include "SystemFacade.h"


SystemFacade::SystemFacade()
{
	LawManager::Get();
}


SystemFacade::~SystemFacade()
{
}

bool SystemFacade::Init()
{

	return true;
}