#pragma once

#include "pch.h"


//***************************************************************
//	Concrete Constraints 
//***************************************************************

class DateConstraint : public IConstraint
{
public:
	DateConstraint(const QDate &s, const QDate &e)
		: m_startDate(s), m_endDate(e)
	{}

	bool Validate(const Declaration &dec) override
	{
		return dec.DeclDate >= m_startDate && dec.DeclDate <= m_endDate;
	}

	std::string toString() override
	{
		std::stringstream ss;
		ss << "Beginning Date is " << m_startDate.toString().toStdString()
			<< " & Ending Date is " << m_endDate.toString().toStdString() << std::endl;

		return ss.str();
	}

private:
	QDate m_startDate;
	QDate m_endDate;
};

class ProductConstraint : public IConstraint
{
public:
	ProductConstraint(const std::vector<std::string> &productVec)
		: m_Products(productVec)
	{}

	bool Validate(const Declaration &dec) override
	{
		for (auto &p : dec.ProductVec)
		{
			if (find(m_Products.begin(), m_Products.end(), p.Name) != m_Products.end())
				return true;
		}
		return false;
	}

	std::string toString() override
	{
		std::stringstream ss;
		ss << "Following product(s) : ";

		for (auto &product : m_Products)
			ss << product << ", ";

		ss << std::endl;

		return ss.str();
	}

private:
	std::vector<std::string> m_Products;
};

class CompanyConstraint : public IConstraint
{
public:
	CompanyConstraint(const std::vector<std::string> &companyVec)
		: m_Companies(companyVec)
	{}

	bool Validate(const Declaration &dec) override
	{
		for (auto &p : dec.ProductVec)
		{
			if (find(m_Companies.begin(), m_Companies.end(), p.Company) != m_Companies.end())
				return true;
		}
		return false;
	}

	std::string toString() override
	{
		std::stringstream ss;

		ss << "Following comapny(s) : ";

		for (auto &company : m_Companies)
			ss << company << ", ";

		ss << std::endl;

		return ss.str();
	}

private:
	std::vector<std::string> m_Companies;
};

class CountryConstraint : public IConstraint
{
public:
	CountryConstraint(const std::vector<std::string> &countries)
		: m_countries(countries)
	{}

	bool Validate(const Declaration &dec) override
	{
		return  (find(m_countries.begin(), m_countries.end(), dec.SourceCountry) != m_countries.end());
	}

	std::string toString() override
	{
		std::stringstream ss;
		ss << "Following Countries : ";

		for (auto &str : m_countries)
			ss << str << ", ";

		ss << std::endl;

		return ss.str();
	}

private:
	std::vector<std::string> m_countries;
};

class ArrivalConstraint : public IConstraint
{
public:
	ArrivalConstraint(ArrivalMethod a)
		: m_arrivalMethod(a)
	{}

	bool Validate(const Declaration &dec) override
	{
		return m_arrivalMethod == dec.Arrival;
	}

	std::string toString() override
	{
		std::stringstream ss;
		ss << "Arrival Method is : " << m_arrivalMethod.toString() << std::endl;
		return ss.str();
	}

private:
	ArrivalMethod m_arrivalMethod;
};

class ValueConstraint : public IConstraint
{
public:
	ValueConstraint(int min, int max, bool unit)
		: m_min(min), m_max(max), m_isUnit(unit)
	{}

	bool Validate(const Declaration &dec) override
	{
		if(!m_isUnit)
			return (dec.TotalValue >= m_min) && (dec.TotalValue <= m_max);

		for (auto &p : dec.ProductVec)
		{
			if (p.Price >= m_min && p.Price <= m_max)
				return true;
		}

		return false;
	}

	std::string toString() override
	{
		std::stringstream ss;
		if (m_isUnit)
			ss << "Unit Product Value :\n";
		else
			ss << "Total Declaration Value :\n";
	
		ss << "Minimum Value : " << m_min << " , Max Value : " << m_max << std::endl;

		return ss.str();
	}

private:
	unsigned int m_min;
	unsigned int m_max;
	bool m_isUnit;
};

//***************************************************************
//	Constraint Decorators
//***************************************************************

template<typename T>
class ConstraintDecorator : public IConstraint
{
public:
	ConstraintDecorator(std::shared_ptr<IConstraint> c, T *dc)
		:m_decoratedConstraint(dc)
	{
		m_Constraint = c;
	}

	bool Validate(const Declaration &dec) override
	{
		if (m_decoratedConstraint->Validate(dec))
			return m_Constraint->Validate(dec);
		else
			return false;
	}

	std::string toString() override { return m_decoratedConstraint->toString().append(m_Constraint->toString()); }

private:
	std::shared_ptr<IConstraint> m_Constraint;

	std::unique_ptr<T> m_decoratedConstraint;
};
	
