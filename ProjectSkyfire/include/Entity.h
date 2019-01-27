////////////////////////////////////////////////////////////
//
// Entity.h
// Created by Dale Sinnott
// 17/12/2018
//
////////////////////////////////////////////////////////////
#ifndef _ENTITY_H_
#define _ENTITY_H_

////////////////////////////////////////////////////////////
// Includes
////////////////////////////////////////////////////////////
///C++
#include <vector>
#include <memory>

///Frox
#include "components/Component.h"


class Entity
{
public:
	////////////////////////////////////////////////////////////
	/// Default constructor
	////////////////////////////////////////////////////////////
	

	////////////////////////////////////////////////////////////
	/// Overloaded constructor
	////////////////////////////////////////////////////////////
	Entity(std::string id) { m_id = id; }

	////////////////////////////////////////////////////////////
	/// Default destructor
	////////////////////////////////////////////////////////////
	~Entity() {
		/*std::cout << "Attempting to delete Entities components safely." << std::endl;
		for (int i = 0; i < m_components.size(); i++)
		{
			delete(m_components.at(i));
		}
		m_components.shrink_to_fit();*/
	}

	////////////////////////////////////////////////////////////
	/// Getters/Setters
	////////////////////////////////////////////////////////////
	void setId(std::string id) { m_id = id; }
	std::string getId() { return m_id; }

	void addComponent(Component *component) { m_components.push_back(component); }
	std::vector<Component*> getComponents() { return m_components; }

private:
	////////////////////////////////////////////////////////////
	/// Member Variables
	////////////////////////////////////////////////////////////
	std::string m_id;
	std::vector<Component*> m_components;

};
#endif;