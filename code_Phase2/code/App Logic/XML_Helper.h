#pragma once

#include "../TinyXML/tinyxml2.h"


class XML_Helper
{
public:

	enum ITEM{PRODUCT, COMPANY, DATE, ARRIVAL, COUNTRY, UNIT_VALUE, TOTAL_VALUE, CERTIFICATE};

	XML_Helper(const char *);
	~XML_Helper();

	bool Init();
	void Save(ITEM i, std::shared_ptr<IEvent>);
	void Finalize(const char *);

private:
	const std::string m_filename;
	std::string m_tempFile;
	std::vector<std::string> m_currCertificates;
	tinyxml2::XMLDocument m_doc;

	bool Load();
	bool CreateTemp();

	inline void LoadProduct(tinyxml2::XMLElement *);
	inline void LoadCompany(tinyxml2::XMLElement *);
	inline void LoadDate(tinyxml2::XMLElement *);
	inline void LoadCountry(tinyxml2::XMLElement *);
	inline void LoadArrival(tinyxml2::XMLElement *);
	inline void LoadUnitValue(tinyxml2::XMLElement *);
	inline void LoadTotalValue(tinyxml2::XMLElement *);
	inline void LoadCertificate(tinyxml2::XMLElement *);

	inline void SaveProduct(tinyxml2::XMLElement *, std::shared_ptr<IEvent>);
	inline void SaveCompany(tinyxml2::XMLElement *, std::shared_ptr<IEvent>);
	inline void SaveDate(tinyxml2::XMLElement *, std::shared_ptr<IEvent>);
	inline void SaveCountry(tinyxml2::XMLElement *, std::shared_ptr<IEvent>);
	inline void SaveArrival(tinyxml2::XMLElement *, std::shared_ptr<IEvent>);
	inline void SaveUnitValue(tinyxml2::XMLElement *, std::shared_ptr<IEvent>);
	inline void SaveTotalValue(tinyxml2::XMLElement *, std::shared_ptr<IEvent>);
	inline void SaveCertificate(tinyxml2::XMLElement *, std::shared_ptr<IEvent>);

	tinyxml2::XMLElement *CreateNewLawNode();
};

