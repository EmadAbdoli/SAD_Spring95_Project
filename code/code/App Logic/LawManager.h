#pragma once

#include "../pch.h"
#include "XML_Helper.h"

class LawManager
{
public:

	static std::shared_ptr<LawManager> Get();

	~LawManager();

private:

	LawManager();
	LawManager(const LawManager &) = delete;
	LawManager &operator=(const LawManager &) = delete;

	static std::shared_ptr<LawManager> m_singletonInstance;
	std::shared_ptr<IConstraint> m_currConstraint;
	std::unordered_map<std::string, std::shared_ptr<IConstraint>> m_lawTable;

	bool m_isModified;
	bool m_isFirstConstraint;
	bool m_loading;

	XML_Helper m_xml;

	void RegisterListeners();
	void LoadFromDisk();
	void SaveToDisk();

	void NewDateConstraint(std::shared_ptr<IEvent>);
	void NewProductConstraint(std::shared_ptr<IEvent>);
	void NewCountryConstraint(std::shared_ptr<IEvent>);
	void NewValueConstraint(std::shared_ptr<IEvent>);
	void NewArrivalConstraint(std::shared_ptr<IEvent>);

	void CreateLaw(std::shared_ptr<IEvent>);
};

