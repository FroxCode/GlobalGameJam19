#include "systems/ControlSystem.h"

void ControlSystem::update(sf::Event e)
{
	std::cout << "ControlSystem update..." << std::endl;
	for (std::vector<Entity*>::iterator i = m_entities.begin(), e = m_entities.end(); i != e; i++)
	{
		for (int j = 0; j < (*i)->getComponents().size(); j++)
		{
			if ((*i)->getComponents().at(j)->getName() == "Component")
			{
				if ((*i)->getId() == "Example")
				{
					//perform on example entitys Component


				}
			}
		}
	}
}