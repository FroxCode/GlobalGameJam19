#ifndef _PERSONALINFORMATIONCOMPONENT_H_
#define _PERSONALINFORMATIONCOMPONENT_H_

#include "Component.h"

class PersonalInformationComponent : public Component
{

private:
	////////////////////////////////////////////////////////////
	/// Member Variables
	////////////////////////////////////////////////////////////
	enum Type {
		BUNGALOW,
		SHACK,
		PRAIRIE,
		MODERN,
		LOG,
		SUBURBAN,
		MEDITERANEAN,
		RANCH,
		BEACH_HOUSE
	};
	Type archType;
	int m_age;
	std::string m_gender;
	std::string m_name;

public:

	////////////////////////////////////////////////////////////
	/// Overloaded constructor
	////////////////////////////////////////////////////////////
	PersonalInformationComponent(int age = 18, std::string name = "error_no_name", std::string gender = "no_gender") : Component("AgeComponent"), m_age(age), m_name(name), m_gender(gender) {}
	////////////////////////////////////////////////////////////
	/// Destructor (for overriding virtual function in abstract 
	/// base Component)
	////////////////////////////////////////////////////////////
	~PersonalInformationComponent() {}

	////////////////////////////////////////////////////////////
	/// Getters/Setters
	////////////////////////////////////////////////////////////
	int getAge() { return m_age; }
	std::string getName() { return m_name; }
	std::string getGender() { return m_gender; }
	std::string getArchType() { 
		switch (archType)
		{
		case PersonalInformationComponent::BUNGALOW:
			return "Bungalow";
			break;
		case PersonalInformationComponent::SHACK:
			return "Shack";
			break;
		case PersonalInformationComponent::PRAIRIE:
			return "Prairie";
			break;
		case PersonalInformationComponent::MODERN:
			return "Modern";
			break;
		case PersonalInformationComponent::LOG:
			return "Log Cabin";
			break;
		case PersonalInformationComponent::SUBURBAN:
			return "Suburban";
			break;
		case PersonalInformationComponent::MEDITERANEAN:
			return "Mediteranean";
			break;
		case PersonalInformationComponent::RANCH:
			return "Ranch";
			break;
		case PersonalInformationComponent::BEACH_HOUSE:
			return "Beach House";
			break;
		default:
			break;
		}
	}


	void setArchType(Type type) {
		archType = type;
		
	}
	void setAge(int age) { m_age = age; }
	void setGender(std::string gender) { m_gender = gender; }
};
#endif;