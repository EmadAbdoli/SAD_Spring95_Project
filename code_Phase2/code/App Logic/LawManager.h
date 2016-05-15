#pragma once

#include "../pch.h"
#include "XML_Helper.h"

class LawManager
{
public:

	static std::shared_ptr<LawManager> Get();

	~LawManager();

private:

	struct Law {
		Law()
		{}
		Law(std::shared_ptr<IConstraint> &co, std::vector<std::string> &ce)
			: cons(co), certificates(ce)
		{}
		std::shared_ptr<IConstraint> cons;
		std::vector<std::string> certificates;
	};

	LawManager();
	LawManager(const LawManager &) = delete;
	LawManager &operator=(const LawManager &) = delete;

	static std::shared_ptr<LawManager> m_singletonInstance;
	std::shared_ptr<IConstraint> m_currConstraint;
	std::unordered_map<std::string, Law> m_lawTable;

	bool m_isFirstConstraint;
	bool m_loading;

	XML_Helper m_xml;

	void RegisterListeners();
	void LoadFromDisk();

	void NewDateConstraint(std::shared_ptr<IEvent>);
	void NewProductConstraint(std::shared_ptr<IEvent>);
	void NewCompanyConstraint(std::shared_ptr<IEvent>);
	void NewCountryConstraint(std::shared_ptr<IEvent>);
	void NewValueConstraint(std::shared_ptr<IEvent>);
	void NewArrivalConstraint(std::shared_ptr<IEvent>);

	void CreateLaw(std::shared_ptr<IEvent>);
	void CheckDeclaration(std::shared_ptr<IEvent>);
};

