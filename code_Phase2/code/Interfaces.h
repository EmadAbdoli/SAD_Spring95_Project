#pragma once

#include <qdatetime.h>

#ifdef _DEBUG						
#ifndef LOG							
#define LOG(x) std::cout << "File : " << __FILE__ << ",\tLine : " << __LINE__ << "\n"  << x;		
#endif
#else								
#define LOG(x) 					
#endif

struct Product{
	std::string Name;
	std::string Company;
	unsigned int Weight;
	unsigned int Count;
	unsigned int Price;
};


class ArrivalMethod {

public:
	ArrivalMethod()
	{
		m_method = AM::AIR;
	}

	explicit ArrivalMethod(std::string &a)
	{
		transform(a.begin(), a.end(), a.begin(), tolower);

		m_method =  (a == "air" ? AM::AIR 
			: (a == "sea" ? AM::SEA : AM::GROUND));
	};

	void Set(const char *c)
	{
		std::string a(c);

		transform(a.begin(), a.end(), a.begin(), tolower);

		m_method = (a == "air" ? AM::AIR
			: (a == "sea" ? AM::SEA : AM::GROUND));
	}

	const char *toString() const 
	{
		return  m_method == AM::AIR ? "Air" : (m_method == AM::GROUND ? "Ground" : "Sea");
	}

	bool operator==(const ArrivalMethod &a)
	{
		return m_method == a.m_method;
	}

private:
	enum AM { AIR, GROUND, SEA };

	AM m_method;
};

struct Declaration {
	int ID;
	int SSN;
	std::string Name;
	QDate DeclDate;
	unsigned int TotalValue;
	std::string SourceCountry;
	ArrivalMethod Arrival;
	unsigned int Count;
	std::vector<Product> ProductVec;
};

struct Certificate {
	int ID;
	std::string Type;
	std::string Name;
	QDate IssueDate;
	QDate ExpireDate;
	unsigned int MaxValue;
	std::string IssuedBy;
};

class IConstraint
{
public:
	virtual bool Validate(const Declaration &) = 0;
	virtual std::string toString() = 0;
};

class IEvent
{
public:
	virtual unsigned int GetType() const = 0;
	virtual const char *GetName() const = 0;
	virtual ~IEvent() {};
};
