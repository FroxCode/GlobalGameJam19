////////////////////////////////////////////////////////////
//
// MenuScene.h
// Created by Dale Sinnott
// 18/12/2018
//
////////////////////////////////////////////////////////////
#ifndef _MENUSCENE_H_
#define _MENUSCENE_H_

////////////////////////////////////////////////////////////
// Includes
////////////////////////////////////////////////////////////
///Frox
#include "Scene.h"
#include "systems/ControlSystem.h"
#include "systems/CollisionSystem.h"
#include "components/BoxColliderComponent.h"


class MenuScene : public Scene
{
public:

	MenuScene(std::string name);
	////////////////////////////////////////////////////////////
	/// Member functions
	////////////////////////////////////////////////////////////
	void initialise(std::shared_ptr<sf::RenderWindow> window);
	void update(sf::Event* e);
	void render(std::shared_ptr<sf::RenderWindow> &window);

	Entity playButton;
	CollisionSystem boinker;
	Entity backgroundImage;
	RenderSystem lilRendy;
	
	const std::string backgroundImagePath = "assets/sprites/menuBackground.png";
	const std::string playButtonImagePath = "assets/sprites/playButton.png";

};
#endif;
