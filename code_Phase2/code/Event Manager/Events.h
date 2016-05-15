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

	Event_DB_New_Permission(std::string &username, std::string & pt, std::string &table)
		: m_username(username), m_permissionType(pt), m_table(table)
	{}

	unsigned int GetType() const override { return m_EventType; }

	const std::string &GetUsername() const { return m_username; }
	const std::string &GetTable() const { return m_table; }
	const std::string &GetPermissionType() const { return m_permissionType; }

private:
	static const unsigned int m_EventType;

	const std::string m_username;
	const std::string m_permissionType;
	const std::string m_table;
};

class Event_DB_New_Declaration : public IEvent
{
public:

	Event_DB_New_Declaration(Declaration &dec)
		: m_dec(dec)
	{};
	
	unsigned int GetType() const override { return m_EventType; }

	const char *GetName() const override
	{
		std::stringstream ss;
		ss << "New Declaration with ID : " << m_dec.ID << std::endl;
		return ss.str().c_str();
	}

	const Declaration &GetDecl() const { return m_dec; }

private:
	static const unsigned int m_EventType;

	Declaration m_dec;
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

class Event_DB_New_Certificate : public IEvent
{
public:
	Event_DB_New_Certificate(Certificate &cer)
		: m_certificate(cer)
	{};

	unsigned int GetType() const override { return m_EventType; }

	const char *GetName() const override
	{
		std::stringstream ss;
		ss << "New certificate with ID : " << m_certificate.ID << std::endl;
		return ss.str().c_str();
	}

	const Certificate &GetCertificate() const { return m_certificate; }

private:
	static const unsigned int m_EventType;

	Certificate m_certificate;
};

class Event_DB_Load_Certificate : public IEvent
{
public:
	Event_DB_Load_Certificate(int id, std::string &t)
		: m_cerID(id), m_type(t)
	{}

	unsigned int GetType() const override { return m_EventType; }
	const char *GetName() const override { return ""; }
	int GetID() { return m_cerID; }
	std::string GetCertificateType() const { return m_type; }

private:
	static const unsigned int m_EventType;
	int m_cerID;
	std::string m_type;
};

class Event_DB_Update_Certificate : public IEvent
{
public:
	Event_DB_Update_Certificate(int c_id, int d_id, std::string &t)
		: m_cerID(c_id), m_decID(d_id), m_type(t)
	{}

	unsigned int GetType() const override { return m_EventType; }
	const char *GetName() const override { return ""; }
	int GetCertID() const { return m_cerID; }
	int GetDecID() const { return m_decID; }
	std::string GetCertificateType() const { return m_type; }

private:
	static const unsigned int m_EventType;
	int m_cerID;
	int m_decID;
	std::string m_type;
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

	Event_UI_Declaration_Retrieved(Declaration &dec)
		: m_dec(dec)
	{};

	unsigned int GetType() const override { return m_EventType; }

	const char *GetName() const override
	{
		std::stringstream ss;
		ss << "Declaration retrieved with ID : " << m_dec.ID << std::endl;
		return ss.str().c_str();
	}

	const Declaration &GetDecl() const { return m_dec; }

private:
	static const unsigned int m_EventType;

	Declaration m_dec;
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

class Event_UI_Certificate_Loaded : public IEvent
{
public:

	Event_UI_Certificate_Loaded(Certificate &cer)
		: m_cer(cer)
	{};

	unsigned int GetType() const override { return m_EventType; }

	const char *GetName() const override
	{
		std::stringstream ss;
		ss << "Certificate retrieved with ID : " << m_cer.ID << std::endl;
		return ss.str().c_str();
	}

	const Certificate &GetCert() const { return m_cer; }

private:
	static const unsigned int m_EventType;

	Certificate m_cer;
};

class Event_UI_Law_Loaded : public IEvent
{
public:
	Event_UI_Law_Loaded(std::string &lawDesc, const std::string &name)
		: m_lawDesc(lawDesc), m_lawName(name)
	{}

	unsigned int GetType() const override { return m_EventType; }
	const char *GetName() const override { return "Law Loaded from disk.\n"; }

	const std::string &GetDesc() const { return m_lawDesc; }
	const std::string &GetLawName() const { return m_lawName; }

private:
	static const unsigned int m_EventType;
	std::string m_lawDesc;
	std::string m_lawName;
};

class Event_UI_Required_Certificates : public IEvent
{
public:
	Event_UI_Required_Certificates(std::vector<std::pair<std::string, std::forward_list<std::string>>> &cv)
		: m_certs(cv)
	{}

	unsigned int GetType() const override { return m_EventType; }
	const char *GetName() const override { return ""; }
	
	std::vector<std::pair<std::string, std::forward_list<std::string>>> GetCertificates() const { return m_certs; }

private:
	static const unsigned int m_EventType;
	std::vector<std::pair<std::string, std::forward_list<std::string>>> m_certs;
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

	Event_Constraint_Product(std::vector<std::string> &prodVec)
		: m_products(prodVec)
	{}

	unsigned int GetType() const override { return m_EventType; }
	const char *GetName() const override	{ return "new product constraint.\n"; }

	const std::vector<std::string> &GetProductNames() const { return m_products; }

private:
	static const unsigned int m_EventType;
	std::vector<std::string> m_products;
};

class Event_Constraint_Company : public IEvent
{
public:

	Event_Constraint_Company(std::vector<std::string> &companyVec)
		: m_companies(companyVec)
	{}

	unsigned int GetType() const override { return m_EventType; }
	const char *GetName() const override { return "new company constraint.\n"; }

	const std::vector<std::string> &GetCompanies() const { return m_companies; }

private:
	static const unsigned int m_EventType;
	std::vector<std::string> m_companies;
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

	const char *GetArrivalMethod() const { return m_arrivalMethod.toString(); }

private:
	static const unsigned int m_EventType;
	ArrivalMethod m_arrivalMethod;
};

class Event_Constraint_Value : public IEvent
{
public:

	Event_Constraint_Value(int min, int max, bool isUnit)
		: m_min(min), m_max(max), m_isUnit(isUnit)
	{}

	unsigned int GetType() const override { return m_EventType; }
	const char *GetName() const override	{ return "new constraint value.\n"; }

	int GetMin() const { return m_min; }
	int GetMax() const { return m_max; }
	bool IsUnit() const { return m_isUnit; }

private:
	static const unsigned int m_EventType;
	int m_min;
	int m_max;
	bool m_isUnit;
};

class Event_Create_Law : public IEvent
{
public:

	Event_Create_Law(std::string &name, std::vector<std::string> &c)
		: m_lawName(name), m_certificates(c)
	{}

	unsigned int GetType() const override { return m_EventType; }
	const char *GetName() const override	{ return "new law created.\n"; }

	const std::string &GetLawName() const { return m_lawName; }
	std::vector<std::string> &GetCertificates() { return m_certificates; }

private:
	static const unsigned int m_EventType;
	std::string m_lawName;
	std::vector<std::string> m_certificates;
};

class Event_CheckWithLaws : public IEvent
{
public:

	Event_CheckWithLaws(Declaration &dec)
		: m_dec(dec)
	{};

	unsigned int GetType() const override { return m_EventType; }

	const char *GetName() const override
	{
		std::stringstream ss;
		ss << "Checking Declaration with ID : " << m_dec.ID << std::endl;
		return ss.str().c_str();
	}

	const Declaration &GetDecl() const { return m_dec; }

private:
	static const unsigned int m_EventType;

	Declaration m_dec;
};



