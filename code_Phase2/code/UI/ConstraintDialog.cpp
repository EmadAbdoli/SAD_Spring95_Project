#include "../pch.h"

#include <QtWidgets>
#include "ConstraintDialog.h"
#include "../Event Manager/Events.h"
#include "../Application/BaseApplication.h"

using namespace MyUi;
using namespace std;


ConstraintDialog::ConstraintDialog()
{
	ui.setupUi(this);
	SetSignals();
}

void ConstraintDialog::SetSignals()
{
	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(ProductConstraint()));
	connect(ui.pushButton_2, SIGNAL(clicked()), this, SLOT(DateConstraint()));
	connect(ui.pushButton_3, SIGNAL(clicked()), this, SLOT(CountryConstraint()));
	connect(ui.pushButton_4, SIGNAL(clicked()), this, SLOT(ValueConstraint()));
	connect(ui.pushButton_5, SIGNAL(clicked()), this, SLOT(ArrivalConstraint()));
	connect(ui.pushButton_6, SIGNAL(clicked()), this, SLOT(CompanyConstraint()));
}

void ConstraintDialog::ProductConstraint()
{
	string products = ui.textEdit->toPlainText().toStdString();

	istringstream iss(products);
	vector<string> tokens{ istream_iterator<string>{iss}, istream_iterator<string>{} };

	shared_ptr<IEvent> evt(make_shared<Event_Constraint_Product>(tokens));
	BaseApplication::Get()->SendEvent(evt);
}

void ConstraintDialog::CompanyConstraint()
{
	string products = ui.textEdit_4->toPlainText().toStdString();

	istringstream iss(products);
	vector<string> tokens{ istream_iterator<string>{iss}, istream_iterator<string>{} };

	shared_ptr<IEvent> evt(make_shared<Event_Constraint_Company>(tokens));
	BaseApplication::Get()->SendEvent(evt);
}

void ConstraintDialog::DateConstraint()
{
	QDate start = ui.dateEdit->date();
	QDate end = ui.dateEdit_2->date();

	shared_ptr<IEvent> evt(make_shared<Event_Constraint_Date>(start, end));
	BaseApplication::Get()->SendEvent(evt);
}

void ConstraintDialog::CountryConstraint()
{
	string countries = ui.textEdit_3->toPlainText().toStdString();

	istringstream iss(countries);
	vector<string> tokens{ istream_iterator<string>{iss}, istream_iterator<string>{} };

	shared_ptr<IEvent> evt(make_shared<Event_Constraint_Country>(tokens));
	BaseApplication::Get()->SendEvent(evt);
}

void ConstraintDialog::ArrivalConstraint()
{
	ArrivalMethod am;

	if (ui.radioButton->isChecked())
		am.Set("air");
	else if (ui.radioButton_2->isChecked())
		am.Set("ground");
	else if (ui.radioButton_3->isChecked())
		am.Set("sea");
	else
	{
		QMessageBox msgBox;
		msgBox.setText("You haven't selected any method.");
		msgBox.exec();
		return;
	}

	shared_ptr<IEvent> evt(make_shared<Event_Constraint_Arrival>(am));
	BaseApplication::Get()->SendEvent(evt);
}

void ConstraintDialog::ValueConstraint()
{
	int min = ui.lineEdit->text().toInt();
	int max = ui.lineEdit_2->text().toInt();

	bool b = (ui.radioButton_5->isChecked());

	shared_ptr<IEvent> evt(make_shared<Event_Constraint_Value>(min, max, b));
	BaseApplication::Get()->SendEvent(evt);
}