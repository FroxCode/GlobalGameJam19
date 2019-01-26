#include "systems/PhysicsSystem.h"
#include "components/SpriteComponent.h"
void PhysicsSystem::update()
{
	///std::cout << "PhysicsSystem update..." << std::endl;
	for (std::vector<Entity*>::iterator i = m_entities.begin(), e = m_entities.end(); i != e; i++)
	{
		for (int j = 0; j < (*i)->getComponents().size(); j++)
		{
			if ((*i)->getComponents().at(j)->getName() == "TransformComponent")
			{
				for (int k = 0; k < (*i)->getComponents().size(); k++)
				{
					if ((*i)->getComponents().at(k)->getName() == "VelocityComponent")
					{
						static_cast<TransformComponent*>((*i)->getComponents().at(j))->setPosition(sf::Vector2f(
							(static_cast<TransformComponent*>((*i)->getComponents().at(j))->getPosition().x +
								static_cast<VelocityComponent*>((*i)->getComponents().at(k))->getVelocity().x),
							(static_cast<TransformComponent*>((*i)->getComponents().at(j))->getPosition().y +
								static_cast<VelocityComponent*>((*i)->getComponents().at(k))->getVelocity().y)
						));
					}
					else if ((*i)->getComponents().at(k)->getName() == "GravityComponent")
					{
						static_cast<TransformComponent*>((*i)->getComponents().at(j))->setPosition(sf::Vector2f(
							(static_cast<TransformComponent*>((*i)->getComponents().at(j))->getPosition().x ),
							(static_cast<TransformComponent*>((*i)->getComponents().at(j))->getPosition().y +
								static_cast<GravityComponent*>((*i)->getComponents().at(k))->getGravityAsVec().y)
						));
					}

					if ((*i)->getComponents().at(k)->getName() == "SpriteComponent")
					{
						if ((*i)->getId() == "playButton")
						{
							if (!swapButtonScale)
							{
								static_cast<TransformComponent*>((*i)->getComponents().at(j))->setScale(sf::Vector2f(
									static_cast<TransformComponent*>((*i)->getComponents().at(j))->getScale().x + 0.005f,
									static_cast<TransformComponent*>((*i)->getComponents().at(j))->getScale().y + 0.005f
								));
								if (static_cast<TransformComponent*>((*i)->getComponents().at(j))->getScale().x > 1.10f)
								{
									swapButtonScale = true;
								}
							}
							else
							{
								static_cast<TransformComponent*>((*i)->getComponents().at(j))->setScale(sf::Vector2f(
									static_cast<TransformComponent*>((*i)->getComponents().at(j))->getScale().x - 0.005f,
									static_cast<TransformComponent*>((*i)->getComponents().at(j))->getScale().y - 0.005f
								));
								if (static_cast<TransformComponent*>((*i)->getComponents().at(j))->getScale().x < 1.0f)
								{
									swapButtonScale = false;
								}
							}
							static_cast<SpriteComponent*>((*i)->getComponents().at(k))->getSprite()->setScale(
								static_cast<TransformComponent*>((*i)->getComponents().at(j))->getScale()
							);
						}
					}
				}
			}
		}
	}
}