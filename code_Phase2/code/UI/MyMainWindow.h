#pragma once

#include "../pch.h"
#include <QtWidgets/QMainWindow>
#include <qlistwidget>
#include "ui_prototype.h"


namespace MyUi{

	class ConstraintDialog;

	class MyMainWindow : public QMainWindow
	{
		Q_OBJECT

	public:
		MyMainWindow(QWidget *parent = 0);
		~MyMainWindow();

		void Init();

	private:
		Ui::prototypeClass ui;
		QAction *m_newAction;
		QAction *m_openAction;
		QAction *m_saveAction;
		QToolBar *m_toolbar;

		ConstraintDialog *m_constraintDialog;

		std::unordered_map<std::string, std::string> m_lawDescs;

		void InitModalDialogs();
		void InitTableWidget();
		void SetSignals();

		void RegisterListeners();
		void PermissionsRetrieved(std::shared_ptr<IEvent>);
		void LawDescUpdated(std::shared_ptr<IEvent>);
		void DeclarationRetrieved(std::shared_ptr<IEvent>);
		void ShowSuccessMsg(std::shared_ptr<IEvent>);
		void CertificateLoaded(std::shared_ptr<IEvent>);
		void LawLoaded(std::shared_ptr<IEvent>);
		void RequiredCertificatesLoaded(std::shared_ptr<IEvent>);

	private slots:
		void NewConstraintDialog();
		void LogIn();
		void NewUser();
		void ChangeCurrentItem(QListWidgetItem * current, QListWidgetItem * previous);
		void NewLaw();
		void LoadDeclaration();
		void SaveDeclaration();
		void AddRow();
		void ClearDeclaration();
		void CheckWithLaws();
		void NewCertificate();
		void LoadCertificate();
		void UpdateCertificate();
	};
}
