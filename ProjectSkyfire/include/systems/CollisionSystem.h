////////////////////////////////////////////////////////////
//
// CollisionSystem.h
// Created by Dale Sinnott
// 17/12/2018
//
////////////////////////////////////////////////////////////
#ifndef _COLLISIONSYSTEM_H_
#define _COLLISIONSYSTEM_H_

////////////////////////////////////////////////////////////
// Includes
////////////////////////////////////////////////////////////
///SFML
#include <SFML\Graphics.hpp>

///Frox
#include "System.h"
#include "components/TransformComponent.h"
#include "components/BoxColliderComponent.h"
#include "components/CircleColliderComponent.h"


class CollisionSystem : public System
{
public:
	void addWindow(std::shared_ptr<sf::RenderWindow> window) { m_window = window; }

	bool checkCollision(sf::Vector2f &point, sf::FloatRect &box);
	bool checkCollision(sf::Vector2i &point, sf::FloatRect &box);

	bool checkCollision(sf::Vector2f &point, sf::IntRect &box);
	bool checkCollision(sf::IntRect &a, sf::IntRect &b);

	float getHorizontalIntersectionDepth(sf::FloatRect &a, sf::FloatRect &b);
	float getVerticalIntersectionDepth(sf::FloatRect &a, sf::FloatRect &b);
	sf::FloatRect asFloatRect(sf::IntRect &rect);

	std::shared_ptr<sf::RenderWindow> m_window;
	void update();

	bool playButtonPressed = false;

};
#endif;