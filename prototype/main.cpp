#include "prototype.h"
#include <QtWidgets/QApplication>
#include <QtWidgets\qstylefactory.h>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

//	a.setStyle(QStyleFactory::create("Fusion"));

	prototype w;
	w.show();
	return a.exec();
}
