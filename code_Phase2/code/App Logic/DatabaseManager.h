#pragma once

#include "../pch.h"
#include <qsqldatabase.h>
#include <qsqlquery.h>
#include <QtSql\qsql.h>

class DatabaseManager
{
public:
	DatabaseManager();
	~DatabaseManager();

private:
	QSqlDatabase m_dbConnection;
	std::string m_currUser;

	void RegisterListeners();

	void LogIn(std::shared_ptr<IEvent>);
	bool LogOut(std::shared_ptr<IEvent>);
	void NewUser(std::shared_ptr<IEvent>);
	void NewPermission(std::shared_ptr<IEvent>);

	void NewDeclaration(std::shared_ptr<IEvent>);
	void LoadDeclaration(std::shared_ptr<IEvent>);

	void NewCertificate(std::shared_ptr<IEvent>);
	void LoadCertificate(std::shared_ptr<IEvent>);
	void UpdateCertificate(std::shared_ptr<IEvent>);

	bool RetrievePrivilleges(std::vector<std::pair<std::string, std::string>> &grantVec);
	bool ParseGrants(std::string &grants, std::string &permission, std::string &table);

	inline bool Execute(QSqlQuery &, const char *);
};

