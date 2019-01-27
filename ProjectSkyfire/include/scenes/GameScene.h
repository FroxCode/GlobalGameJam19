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
#include "systems/CollisionSystem.h"
#include "components/TextComponent.h"

class GameScene : public Scene
{
public:
	////////////////////////////////////////////////////////////
	/// Member functions
	////////////////////////////////////////////////////////////
	GameScene(std::string name) : Scene(name), diallyBoi("diallyBoi"),
	buttonOne("buttonOne"), buttonTwo("buttonTwo"), buttonThree("buttonThree"), backgroundImage("backgroundImage"),
		dateOne("dateOne"),	dateTwo("dateTwo"),	dateThree("dateThree"), realEstateAgent("realEstateAgent"){}
	void initialise(std::shared_ptr<sf::RenderWindow> &window);
	void update(sf::Event* e);
	void render(std::shared_ptr<sf::RenderWindow> &window);

	enum GameStates { Intro, ChooseStage, InStage, HouseChoice, End }; 
	enum Stages { StageOne, StageTwo, StageThree };
	enum DateNumber { First, Second, Third };
	enum Dialogues { DateIntro, IntroResponse, ThisOrThat, ThisOrThatResponse,
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

	void introRender(std::shared_ptr<sf::RenderWindow> window);
	void choiceRender(std::shared_ptr<sf::RenderWindow> &window);
	void stageRender(std::shared_ptr<sf::RenderWindow> &window);
	void houseChoiceRender(std::shared_ptr<sf::RenderWindow> &window);
	void endGameRender(std::shared_ptr<sf::RenderWindow> &window);

	void introInit();
	void choiceInit();
	void stageInit();
	void houseChoiceInit();
	void endGameInit();

	std::string getButtonText(GameStates gameState, int button);
	void resetButtons(int num = 2);

	void factoryRecreateButtons(int buttons = 2);
	std::string getCharacterAnswers(int button, GameScene::Dialogues questionPhase);

	std::string fontName = "assets/fonts/default.ttf";
	std::string dealerImagePath = "assets/sprites/Characters/RealEstateAgent.png";
	std::string dialBoxName = "assets/sprites/speechBubble.png";
	std::string backgroundImagePath = "assets/sprites/Locations/EstateAgentsOffice.png";


	sf::Vector2f leftPos = sf::Vector2f(50, 850);
	sf::Vector2f midPos = sf::Vector2f(650, 850);
	sf::Vector2f rightPos = sf::Vector2f(1250, 850);

	sf::Vector2f buttonScale = sf::Vector2f(0.75f, 0.25f);
	std::string getConversationButtonText(int button , GameScene::DateNumber dateNumber);

	bool click = false;
	int responseStrength;
//////////////////////////////////SYSTEMS//////////////////////////////
	CollisionSystem boinkor;
	RenderSystem lilRendo;


//////////////////////////////////ENTITIES/////////////////////////////
	Entity buttonOne;
	Entity buttonTwo;
	Entity buttonThree;

	Entity diallyBoi; 

	Entity* currentDate;
	Entity dateOne;
	Entity dateTwo;
	Entity dateThree;

	Entity realEstateAgent;
	Entity backgroundImage;

};
#endif;
