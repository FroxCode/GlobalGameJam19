////////////////////////////////////////////////////////////
//
// Created by Dale Sinnott
//
////////////////////////////////////////////////////////////
#ifndef _SceneManager_H_
#define _SceneManager_H_
////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML\Graphics.hpp>
#include <iostream>
#include <memory>
#include <string>
#include "scenes/Scene.h"
#include "scenes/MenuScene.h"
#include "scenes/GameScene.h"

class SceneManager
{
public:
	////////////////////////////////////////////////////////////
	/// Default constructor
	///
	////////////////////////////////////////////////////////////
	SceneManager();

	////////////////////////////////////////////////////////////
	/// Default destructor
	///
	////////////////////////////////////////////////////////////
	~SceneManager();
	std::string currentSceneName;
	void fixedUpdate(sf::Event* evt);
	void render(std::shared_ptr<sf::RenderWindow> window);
	void setScene(std::string name);
	std::vector<Scene*> scenes;
	void initialise(std::shared_ptr<sf::RenderWindow> window);

	std::shared_ptr<sf::RenderWindow> w;
	GameScene* gameScene;
	MenuScene* menuScene;

};
#endif;