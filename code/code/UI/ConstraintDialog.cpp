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
}

void ConstraintDialog::ProductConstraint()
{
	string products = ui.textEdit->toPlainText().toStdString();
	string companies = ui.textEdit_2->toPlainText().toStdString();

	istringstream iss(products);
	vector<string> tokens{ istream_iterator<string>{iss}, istream_iterator<string>{} };

	istringstream iss2(companies);
	vector<string> tokens2{ istream_iterator<string>{iss}, istream_iterator<string>{} };

	shared_ptr<IEvent> evt(make_shared<Event_Constraint_Product>(tokens, tokens2));
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
	string countries = ui.textEdit->toPlainText().toStdString();

	istringstream iss(countries);
	vector<string> tokens{ istream_iterator<string>{iss}, istream_iterator<string>{} };

	shared_ptr<IEvent> evt(make_shared<Event_Constraint_Country>(tokens));
	BaseApplication::Get()->SendEvent(evt);
}

void ConstraintDialog::ArrivalConstraint()
{
/*	ARRIVAL_METHOD am;

	if (ui.radioButton->isChecked())
		am = ARRIVAL_METHOD::AIR;
	else if (ui.radioButton_2->isChecked())
		am = ARRIVAL_METHOD::GROUND;
	else if (ui.radioButton_3->isChecked())
		am = ARRIVAL_METHOD::SEA;
	else
	{
		QMessageBox msgBox;
		msgBox.setText("You haven't selected any type.");
		msgBox.exec();
		return;
	}

	shared_ptr<IEvent> evt(make_shared<Event_Constraint_Arrival>(am));
	BaseApplication::Get()->SendEvent(evt);
	*/
}

void ConstraintDialog::ValueConstraint()
{
	int min = ui.lineEdit->text().toInt();
	int max = ui.lineEdit_2->text().toInt();

	shared_ptr<IEvent> evt(make_shared<Event_Constraint_Value>(min, max));
	BaseApplication::Get()->SendEvent(evt);
}