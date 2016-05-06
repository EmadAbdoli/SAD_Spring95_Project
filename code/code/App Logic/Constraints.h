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
		return dec.DeclDate >= m_startDate;
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
	ProductConstraint(const std::vector<std::string> &productVec, const std::vector<std::string> &companyVec)
		: m_Products(productVec), m_Companies(companyVec)
	{}

	bool Validate(const Declaration &dec) override
	{
		for (auto &p : dec.ProductVec)
		{
			if (find(m_Products.begin(), m_Products.end(), p.Name) == m_Products.end())
				return true;
			if (find(m_Companies.begin(), m_Companies.end(), p.Company) == m_Companies.end())
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

		ss << "Following comapny(s) : ";

		for (auto &company : m_Companies)
			ss << company << ", ";

		ss << std::endl;

		return ss.str();
	}

private:
	std::vector<std::string> m_Products;
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
	ValueConstraint(int min, int max)
		: m_min(min), m_max(max)
	{}

	bool Validate(const Declaration &dec) override
	{
		return (dec.TotalValue >= m_min) && (dec.TotalValue <= m_max);
	}

	std::string toString() override
	{
		std::stringstream ss;
		ss << "Minimum Value : " << m_min << " ,Max Value : " << m_max << std::endl;

		return ss.str();
	}

private:
	unsigned int m_min;
	unsigned int m_max;
};

//***************************************************************
//	Constraint Decorators
//***************************************************************

class IConstraintDecorator : public IConstraint
{
protected:
	std::shared_ptr<IConstraint> m_Constraint;
};

class DateDecorator : public IConstraintDecorator
{
public:
	DateDecorator(std::shared_ptr<IConstraint> c, const QDate &s, const QDate &e)
		: m_dateConstraint(new DateConstraint(s, e))
	{ 
		m_Constraint = c;
	}

	bool Validate(const Declaration &dec) override
	{
		if (m_dateConstraint->Validate(dec))
			return m_Constraint->Validate(dec);
		else
			return false;
	}

	std::string toString() override { return m_dateConstraint->toString().append(m_Constraint->toString()); }

private:
	std::unique_ptr<DateConstraint> m_dateConstraint;
};

class ProductDecorator : public IConstraintDecorator
{
public:
	ProductDecorator(std::shared_ptr<IConstraint> c, const std::vector<std::string> &pn, const std::vector<std::string> &cn)
		: m_productConstraint(new ProductConstraint(pn, cn))
	{
		m_Constraint = c;
	}

	bool Validate(const Declaration &dec) override
	{
		if (m_productConstraint->Validate(dec))
			return m_Constraint->Validate(dec);
		else
			return false;
	}

	std::string toString() override { return m_productConstraint->toString().append(m_Constraint->toString()); }

private:
	std::unique_ptr<ProductConstraint> m_productConstraint;
};

class CountryDecorator : public IConstraintDecorator
{
public:
	CountryDecorator(std::shared_ptr<IConstraint> c, const std::vector<std::string> &countries)
		: m_countryConstraint(new CountryConstraint(countries))
	{
		m_Constraint = c;
	}

	bool Validate(const Declaration &dec) override
	{
		if (m_countryConstraint->Validate(dec))
			return m_Constraint->Validate(dec);
		else
			return false;
	}

	std::string toString() override { return m_countryConstraint->toString().append(m_Constraint->toString()); }

private:
	std::unique_ptr<CountryConstraint> m_countryConstraint;
};

class ArrivalDecorator : public IConstraintDecorator
{
public:
	ArrivalDecorator(std::shared_ptr<IConstraint> c, ArrivalMethod a)
		: m_arrivalConstraint(new ArrivalConstraint(a))
	{
		m_Constraint = c;
	}

	bool Validate(const Declaration &dec) override
	{
		if (m_arrivalConstraint->Validate(dec))
			return m_Constraint->Validate(dec);
		else
			return false;
	}

	std::string toString() override { return m_arrivalConstraint->toString().append(m_Constraint->toString()); }

private:
	std::unique_ptr<ArrivalConstraint> m_arrivalConstraint;
};

class ValueDecorator : public IConstraintDecorator
{
public:
	ValueDecorator(std::shared_ptr<IConstraint> c, int min, int max)
		: m_valueConstraint(new ValueConstraint(min, max))
	{
		m_Constraint = c;
	}

	bool Validate(const Declaration &dec) override
	{
		if (m_valueConstraint->Validate(dec))
			return m_Constraint->Validate(dec);
		else
			return false;
	}

	std::string toString() override { return m_valueConstraint->toString().append(m_Constraint->toString()); }

private:
	std::unique_ptr<ValueConstraint> m_valueConstraint;
};

