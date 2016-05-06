#pragma once
#include "../pch.h"

//****************************************************************
//	Database Events
//****************************************************************

class Event_DB_Log_In : public IEvent
{
public:
	Event_DB_Log_In(std::string &username, std::string &password)
		: m_username(username), m_password(password)
	{}

	unsigned int GetType() const override { return m_EventType; }

	const char *GetName() const override
	{
		std::stringstream ss;
		ss << "Log In from user " << m_username << std::endl;

		return ss.str().c_str();
	}

	const std::string &GetUsername() const { return m_username; }
	const std::string &GetPassword() const { return m_password; }

private:
	static const unsigned int m_EventType;

	const std::string m_username;
	const std::string m_password;
};

class Event_DB_New_User : public IEvent
{
public:
	Event_DB_New_User(std::string &username, std::string &password)
		: m_username(username), m_password(password)
	{}

	unsigned int GetType() const override { return m_EventType; }

	const char *GetName() const override
	{
		std::stringstream ss;
		ss << "New user " << m_username << " created.\n";

		return ss.str().c_str(); 
	}

	const std::string &GetUsername() const { return m_username; }
	const std::string &GetPassword() const { return m_password; }

private:
	static const unsigned int m_EventType;

	const std::string m_username;
	const std::string m_password;
};

class Event_DB_New_Permission : public IEvent
{
public:

	enum PERMISSION_TYPE {SELECT, UPDATE, REMOVE};

	Event_DB_New_Permission(std::string &username, PERMISSION_TYPE pt, std::string &table)
		: m_username(username), m_permissionType(pt), m_table(table)
	{}

	unsigned int GetType() const override { return m_EventType; }

	const std::string &GetUsername() const { return m_username; }
	const std::string &GetTable() const { return m_table; }
	const char *GetPermissionType() const 
	{ 
		return (m_permissionType == SELECT ? "select" : (m_permissionType == UPDATE ? "update" : "remove"));
	}

private:
	static const unsigned int m_EventType;

	const std::string m_username;
	PERMISSION_TYPE m_permissionType;
	const std::string m_table;
};

class Event_DB_New_Declaration : public IEvent
{
public:

	Event_DB_New_Declaration(Declaration &dec, std::vector<Product> &prodVec)
		: m_dec(dec), m_ProdVec(prodVec)
	{};
	
	unsigned int GetType() const override { return m_EventType; }

	const char *GetName() const override
	{
		std::stringstream ss;
		ss << "New Declaration with ID : " << m_dec.ID << std::endl;
		return ss.str().c_str();
	}

	const Declaration &GetDecl() const { return m_dec; }
	const std::vector<Product> &GetProducts() const { return m_ProdVec; }

private:
	static const unsigned int m_EventType;

	Declaration m_dec;
	std::vector<Product> m_ProdVec;
};

class Event_DB_Load_Declaration : public IEvent
{
public :
	Event_DB_Load_Declaration(int id)
		: m_declID(id)
	{};

	unsigned int GetType() const override { return m_EventType; }
	const char *GetName() const override { return ""; }
	int GetID() { return m_declID; }

private:
	static const unsigned int m_EventType;
	int m_declID;
};

//****************************************************************
//	GUI Events
//****************************************************************

class Event_UI_Permissions_Retrieved : public IEvent
{
public:
	Event_UI_Permissions_Retrieved(std::vector<std::pair<std::string, std::string>> &p)
		: m_permisssionVec(p)
	{}

	unsigned int GetType() const override { return m_EventType; }
	const char *GetName() const override	{ return "Permissions Retrieved.\n"; }

	const std::vector<std::pair<std::string, std::string>> &GetPermissions() const { return m_permisssionVec; };

private:
	static const unsigned int m_EventType;

	std::vector<std::pair<std::string, std::string>> m_permisssionVec;
};

class Event_UI_Update_Law_Desc : public IEvent
{
public:
	Event_UI_Update_Law_Desc(const std::string &law)
		: m_law(law)
	{}

	unsigned int GetType() const override { return m_EventType; }
	const char *GetName() const override	{ return "Update law description.\n"; }
	const std::string &GetLawDescription() { return m_law; }

private:
	static const unsigned int m_EventType;
	const std::string m_law;
};

class Event_UI_Declaration_Retrieved : public IEvent
{
public:

	Event_UI_Declaration_Retrieved(Declaration &dec, std::vector<Product> &prodVec)
		: m_dec(dec), m_ProdVec(prodVec)
	{};

	unsigned int GetType() const override { return m_EventType; }

	const char *GetName() const override
	{
		std::stringstream ss;
		ss << "Declaration retrieved with ID : " << m_dec.ID << std::endl;
		return ss.str().c_str();
	}

	const Declaration &GetDecl() const { return m_dec; }
	const std::vector<Product> &GetProducts() const { return m_ProdVec; }

private:
	static const unsigned int m_EventType;

	Declaration m_dec;
	std::vector<Product> m_ProdVec;
};

class Event_UI_Success : public IEvent
{
public:
	Event_UI_Success(const char *t)
		: m_successMsg(t)
	{}

	unsigned int GetType() const override { return m_EventType; }

	const char *GetName() const override  { return "Operation Successful"; }
	const char *GetText() const { return m_successMsg; }

private:
	static const unsigned int m_EventType;
	const char *m_successMsg;

};

//****************************************************************
//	Law & Constraint Events
//****************************************************************

class Event_Constraint_Date : public IEvent
{
public:

	Event_Constraint_Date(QDate &d, QDate &e)
		: m_start(d), m_end(e)
	{}

	unsigned int GetType() const override { return m_EventType; }
	const char *GetName() const override	{ return "New date constraint.\n"; }

	void GetDate(QDate &s, QDate &e) const { s = m_start; e = m_end; }

private:
	static const unsigned int m_EventType;
	QDate m_start;
	QDate m_end;
};

class Event_Constraint_Product : public IEvent
{
public:

	Event_Constraint_Product(std::vector<std::string> &prodVec, std::vector<std::string> &companyVec,
		unsigned int min = 0, unsigned int max = INT_MAX)
		: m_products(prodVec), m_companies(companyVec), m_minValue(min), m_maxValue(max)
	{}

	unsigned int GetType() const override { return m_EventType; }
	const char *GetName() const override	{ return "new product constraint.\n"; }

	const std::vector<std::string> &GetProductNames() const { return m_products; }
	const std::vector<std::string> &GetCompanies() const { return m_companies; }
	void GetValues(int &min, int &max) const { min = m_minValue; max = m_maxValue; }

private:
	static const unsigned int m_EventType;
	std::vector<std::string> m_products;
	std::vector<std::string> m_companies;
	unsigned int m_minValue;
	unsigned int m_maxValue;
};

class Event_Constraint_Country : public IEvent
{
public:

	Event_Constraint_Country(std::vector<std::string> &countryVec)
		: m_countries(countryVec)
	{}

	unsigned int GetType() const override { return m_EventType; }
	const char *GetName() const override	{ return "new country constraint.\n"; }

	const std::vector<std::string> &GetCountries() const { return m_countries; }

private:
	static const unsigned int m_EventType;
	std::vector<std::string> m_countries;
};

class Event_Constraint_Arrival : public IEvent
{
public:

	Event_Constraint_Arrival(ArrivalMethod a)
		: m_arrivalMethod(a)
	{}

	unsigned int GetType() const override { return m_EventType; }
	const char *GetName() const override	{ return "new arrival constraint.\n"; }

	ArrivalMethod GetArrivalMethod() const { return m_arrivalMethod; }

private:
	static const unsigned int m_EventType;
	ArrivalMethod m_arrivalMethod;
};

class Event_Constraint_Value : public IEvent
{
public:

	Event_Constraint_Value(int min, int max)
		: m_min(min), m_max(max)
	{}

	unsigned int GetType() const override { return m_EventType; }
	const char *GetName() const override	{ return "new constraint value.\n"; }

	int GetMin() const { return m_min; }
	int GetMax() const { return m_max; }

private:
	static const unsigned int m_EventType;
	int m_min;
	int m_max;
};

class Event_Create_Law : public IEvent
{
public:

	Event_Create_Law(std::string &name)
		: m_lawName(name)
	{}

	unsigned int GetType() const override { return m_EventType; }
	const char *GetName() const override	{ return "new law created.\n"; }

	const std::string &GetLawName() const { return m_lawName; }

private:
	static const unsigned int m_EventType;
	std::string m_lawName;
};
