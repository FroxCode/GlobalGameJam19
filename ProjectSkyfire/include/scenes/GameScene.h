////////////////////////////////////////////////////////////
//
// GameScene.h
// Created by Dale Sinnott
// 18/12/2018
//
////////////////////////////////////////////////////////////
#ifndef _GAMESCENE_H_
#define _GAMESCENE_H_

////////////////////////////////////////////////////////////
// Includes
////////////////////////////////////////////////////////////
///Frox
#include "Scene.h"

class GameScene : public Scene
{
public:
	////////////////////////////////////////////////////////////
	/// Member functions
	////////////////////////////////////////////////////////////
	GameScene(std::string name) : Scene(name),
	dummy("dummy") {}

	void initialise(std::shared_ptr<sf::RenderWindow> &window);
	void update(sf::Event* e);
	void render(std::shared_ptr<sf::RenderWindow> &window);

	enum GameStates { Intro, ChooseStage, InStage, HouseChoice, End }; 
	enum Stages { StageOne, StageTwo, StageThree };
	enum DateNumber { First, Second, Third };
	enum Dialogues { Intro, IntroResponse, ThisOrThat, ThisOrThatResponse,
		GettingToKnowYou, GettingToKnowYouResponse, OverallResponse };
	enum ResponseTypes { Bad, Neutral, Good };

	GameStates gameState = GameStates::Intro;
	Stages stage;
	DateNumber dateNumber;
	Dialogues dialogue;
	ResponseTypes responseType;

	void introUpdate();
	void choiceUpdate();
	void stageUpdate();
	void houseChoiceUpdate();
	void endGameUpdate();

	bool goToMainMenu = false;

	void introRender();
	void choiceRender();
	void stageRender();
	void houseChoiceRender();
	void endGameUpdate();

	void introInit();
	void choiceInit();
	void stageInit();
	void houseChoiceInit();
	void endGameInit();

	void factoryRecreateButtons()

	std::string fontName = "assets/fonts/default.ttf";
	std::string dialBoxName = "assets/sprites/speechBubble.png"

	sf::Vector2f leftPos = sf::Vector2f(110, 800);
	sf::Vector2f midPos = sf::Vector2f(710, 800);
	sf::Vector2f rightPos = sf::Vector2f(1310, 800);

	sf::Vector2f buttonScale = sf::Vector2f(0.75f, 0.5f);

//////////////////////////////////SYSTEMS//////////////////////////////
	CollisionSystem boinker;

//////////////////////////////////ENTITIES/////////////////////////////
	Entity buttonOne;
	Entity buttonTwo;
	Entity buttonThree;
};
#endif;
