//Created by Dale Sinnott
#include "SceneManager.h"
#include <iostream>

SceneManager::SceneManager()
{

}
SceneManager::~SceneManager()
{

}
void SceneManager::initialise()
{
	MenuScene* menuScene = new MenuScene("Menu");
	menuScene->initialise();
	scenes.push_back(menuScene);
	currentSceneName = "Menu";
	std::cout << "init scene manager" << std::endl;

	GameScene* gameScene = new GameScene("Game");
	scenes.push_back(gameScene);
	
}
void SceneManager::fixedUpdate(sf::Event* evt)
{//spaghetti
	for (std::vector<Scene*>::iterator i = scenes.begin(), e = scenes.end(); i != e; i++) {
		if ((*i)->getName() == currentSceneName)
		{
			(*i)->update(evt);
		}
	}
}
void SceneManager::render(std::shared_ptr<sf::RenderWindow> window)
{
	for (std::vector<Scene*>::iterator i = scenes.begin(), e = scenes.end(); i != e; i++) {
		if ((*i)->getName() == currentSceneName)
		{
			(*i)->render(window);
		}
	}
}
void SceneManager::setScene(std::string targetSceneName)
{
	currentSceneName = targetSceneName;
}
