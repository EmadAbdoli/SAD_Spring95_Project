#ifndef PROTOTYPE_H
#define PROTOTYPE_H

#include <QtWidgets/QMainWindow>
#include "ui_prototype.h"

class prototype : public QMainWindow
{
	Q_OBJECT

public:
	prototype(QWidget *parent = 0);
	~prototype();

private:
	Ui::prototypeClass ui;
};

#endif // PROTOTYPE_H
