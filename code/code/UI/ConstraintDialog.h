#pragma once

#include "ui_constraintdialog.h"

namespace MyUi{

	class ConstraintDialog : public QDialog
	{
		Q_OBJECT

	public:
		ConstraintDialog();

	private:
		Ui::Dialog ui;

		void SetSignals();

	private slots:
		void ProductConstraint();
		void DateConstraint();
		void CountryConstraint();
		void ArrivalConstraint();
		void ValueConstraint();
	};
}

