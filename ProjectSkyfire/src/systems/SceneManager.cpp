//Created by Dale Sinnott
#include "SceneManager.h"
#include <iostream>

SceneManager::SceneManager()
{

}
SceneManager::~SceneManager()
{

}
void SceneManager::initialise(std::shared_ptr<sf::RenderWindow> window)
{
	menuScene = new MenuScene("Menu");
	menuScene->initialise(window);
	scenes.push_back(menuScene);
	currentSceneName = "Menu";
	std::cout << "init scene manager" << std::endl;

	gameScene = new GameScene("Game");
	scenes.push_back(gameScene);
	
}
void SceneManager::fixedUpdate(sf::Event* evt)
{//spaghetti

	if (currentSceneName == "Menu")
	{
		for (std::vector<Scene*>::iterator i = scenes.begin(), e = scenes.end(); i != e; i++) {
			if ((*i)->getName() == "Menu")
			{
				static_cast<MenuScene*>(*i)->update(evt);
				if (static_cast<MenuScene*>(*i)->boinker.playButtonPressed)
				{
					setScene("Game");
				}
			}
		}
	}
	else if (currentSceneName == "Game")
	{
		for (std::vector<Scene*>::iterator i = scenes.begin(), e = scenes.end(); i != e; i++) {
			if ((*i)->getName() == "Game")
			{
				static_cast<GameScene*>(*i)->update(evt);
				std::cout << "Updating game scene" << std::endl;
			}
		}
	}
}
void SceneManager::render(std::shared_ptr<sf::RenderWindow> window)
{
	if (currentSceneName == "Menu")
	{
		for (std::vector<Scene*>::iterator i = scenes.begin(), e = scenes.end(); i != e; i++) {
			if ((*i)->getName() == "Menu")
			{
				static_cast<MenuScene*>(*i)->render(window);
			}
		}
	}
	else if (currentSceneName == "Game")
	{
		for (std::vector<Scene*>::iterator i = scenes.begin(), e = scenes.end(); i != e; i++) {
			if ((*i)->getName() == "Game")
			{
				static_cast<GameScene*>(*i)->render(window);
			}
		}
	}
}
void SceneManager::setScene(std::string targetSceneName)
{
	currentSceneName = targetSceneName;
}
