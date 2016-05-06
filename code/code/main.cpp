#include <QtWidgets/QApplication>
#include "SystemFacade.h"
#include "console.h"


int main(int argc, char *argv[])
{
#if defined(_DEBUG) || defined(DEBUG)
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

	RedirectIOToConsole();

	std::cout << "Test...\n";

	QApplication a(argc, argv);

	SystemFacade f;

	return a.exec();
}
