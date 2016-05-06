#pragma once

#include "../TinyXML/tinyxml2.h"


class XML_Helper
{
public:

	enum ITEM{PRODUCT, DATE, VALUE, ARRIVAL, COUNTRY};

	XML_Helper(const char *);
	~XML_Helper();

	bool Init();
	void Save(ITEM i, std::shared_ptr<IEvent>);
	void Finalize();

private:
	const std::string m_filename;
	std::string m_tempFile;

	bool Load();
	bool CreateTemp();

	inline void LoadProduct(tinyxml2::XMLElement *);
	inline void LoadDate(tinyxml2::XMLElement *);
	inline void LoadCountry(tinyxml2::XMLElement *);
	inline void LoadArrival(tinyxml2::XMLElement *);
	inline void LoadValue(tinyxml2::XMLElement *);

	inline void SaveProduct(std::shared_ptr<IEvent>);
	inline void SaveDate(std::shared_ptr<IEvent>);
	inline void SaveCountry(std::shared_ptr<IEvent>);
	inline void SaveArrival(std::shared_ptr<IEvent>);
	inline void SaveValue(std::shared_ptr<IEvent>);
};

