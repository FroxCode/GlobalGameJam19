#include "scenes/GameScene.h"
#include "Dialog.h"
void GameScene::initialise(std::shared_ptr<sf::RenderWindow> &window) 
{

	diallyBoi.addComponent(new TextComponent());
	diallyBoi.addComponent(new SpriteComponent(dialBoxName));
	diallyBoi.addComponent(new TransformComponent());

	realEstateAgent.addComponent(new SpriteComponent(dealerImagePath));
	realEstateAgent.addComponent(new TransformComponent(sf::Vector2f(1280, 120)));

	backgroundImage.addComponent(new SpriteComponent(backgroundImagePath));
	backgroundImage.addComponent(new TransformComponent());

	overlay.addComponent(new SpriteComponent(overlayPath));
	overlay.addComponent(new TransformComponent);

	remy.addComponent(new SpriteComponent(remyPath));
	remy.addComponent(new TransformComponent);


	static_cast<TextComponent*>(diallyBoi.getComponents().at(0))->getText()->setString("Hello");	
	static_cast<TransformComponent*>(diallyBoi.getComponents().at(2))->setPosition(sf::Vector2f(20,20));
	static_cast<SpriteComponent*>(diallyBoi.getComponents().at(1))->getSprite()->setColor(sf::Color(
		static_cast<SpriteComponent*>(diallyBoi.getComponents().at(1))->getSprite()->getColor().r,
		static_cast<SpriteComponent*>(diallyBoi.getComponents().at(1))->getSprite()->getColor().g,
		static_cast<SpriteComponent*>(diallyBoi.getComponents().at(1))->getSprite()->getColor().b,
		150)
	);


	lilRendo.addEntity(&backgroundImage);

	lilRendo.addEntity(&realEstateAgent);
	lilRendo.addEntity(&diallyBoi);


	lilRendo.addEntity(&buttonOne);
	lilRendo.addEntity(&buttonTwo);
	lilRendo.addEntity(&buttonThree);

	boinkor.addWindow(window);
	boinkor.addEntity(&buttonOne);
	boinkor.addEntity(&buttonTwo);
	boinkor.addEntity(&buttonThree);

	resetButtons();

	switch (gameState)
	{
	case GameScene::Intro:
		gameState = GameStates::Intro;
		stage = Stages::StageOne;
		dateNumber = DateNumber::First;
		dialogue = Dialogues::DateIntro;
		responseType = ResponseTypes::Neutral;
		//load intro
		introInit();
		break;
	case GameScene::ChooseStage:
		//load choose stage screen + dealerIntro	
		break;
	case GameStates::InStage:
		switch (stage)
		{
		case GameScene::StageOne:
			//load first 3 houses 
			break;
		case GameScene::StageTwo:
			//load next 3 houses
			break;
		case GameScene::StageThree:
			//load last 3 houses
			break;
		default:
			break;
		}
		break;
	case GameScene::HouseChoice:
		//load house choice screen
		
	case GameScene::End:
		//load end screen
		break;
	default:
		break;
	}
}
void GameScene::update(sf::Event* e)
{
	boinkor.update();
	switch (gameState)
	{
	case GameScene::Intro:
		introUpdate();
		//show dialogue of what happens in game
		break;
	case GameScene::ChooseStage:
		choiceUpdate();
		//if (method returning which number 0/1/2 was clicked)
		//{
			//switch (that method return int)
			//{
			//case GameScene::StageOne:
				//gameState = GameScene::InStage;
				//stage = GameScene::StageOne;
			//	break;
			//case GameScene::StageTwo:
			//	break;
			//case GameScene::StageThree:
			//	break;
			//default:
			//	break;
			//}
		//}
		break;
	case GameScene::InStage:
		stageUpdate(); //update Stage 
		break;
	case GameScene::HouseChoice:
		houseChoiceUpdate();
		break;
	case GameScene::End:
		endGameUpdate();
		break;
	default:
		goToMainMenu = true;
		break;
	}
}
void GameScene::render(std::shared_ptr<sf::RenderWindow> &window)
{
	lilRendo.update(window);
}

void GameScene::introUpdate()
{
	switch (boinkor.buttonPressed)
	{
	case 0:
		if (click)
		{
			lilRendo.addEntity(&overlay);
			break;
		}
		lilRendo.addEntity(&remy);
		boinkor.buttonPressed = -1;
		Sleep(1000);
		click = true;
		break;
	case 1:
		if (click)
		{
			lilRendo.addEntity(&overlay);
			break;
		}
		lilRendo.addEntity(&remy);
		boinkor.buttonPressed = -1;
		Sleep(1000);
		click = true;
		break;
	case 2:
		if (click)
		{
			lilRendo.addEntity(&overlay);
			break;
		}
		lilRendo.addEntity(&remy);
		boinkor.buttonPressed = -1;
		Sleep(1000);
		click = true;
		break;
	default:
		//do nothing
		break;
	}
	//display intro dialogue using systems (make them)
	//checkcollision on 3 buttons jhiudwused globally in scene everychoice (less duplication)
	//if yes on one, get that number 0 1 2
}
void GameScene::choiceUpdate()
{
	switch (boinkor.buttonPressed)
	{
	case 0:

		break;
	case 1:
		break;
	case 2:
		break;
	default:
		break;
	}
}
void GameScene::stageUpdate()
{
	switch (stage)
	{
	case GameScene::StageOne:
		//houseChoiceUpdate();
		break;
	case GameScene::StageTwo:
		//houseChoiceUpdate();
		break;
	case GameScene::StageThree:
		//houseChoiceUpdate();
		break;
	default:
		break;
	}
}
void GameScene::houseChoiceUpdate()
{

}
void GameScene::endGameUpdate()
{

}
void GameScene::introInit()
{
	factoryRecreateButtons();
}

void GameScene::factoryRecreateButtons(int buttons)//GameStates gameState, int buttons = 2)
{
	for(int i = 0; i < 2; i++)
	{
		switch (i)
		{
			case 0:
				resetButtons(0);
				static_cast<TextComponent*>(buttonOne.getComponents().at(1))->getText()->setString(
					getButtonText(gameState, i)
				);
				break;
			case 1:
				resetButtons(1);
				static_cast<TextComponent*>(buttonTwo.getComponents().at(1))->getText()->setString(
					getButtonText(gameState, i)
				);
				break;
			case 2:
				resetButtons(2);
				static_cast<TextComponent*>(buttonThree.getComponents().at(1))->getText()->setString(
					getButtonText(gameState, i)
				);
				break;
			default:
				break;
		}
	}
	
}
std::string GameScene::getButtonText(GameStates gameState, int button)
{
	switch (gameState)
	{
	case GameScene::Intro:
		//"Hey there"
		return "Continue.."; //intro string option to go to choose stage
		break;
	case GameScene::ChooseStage:
		//"Choose your neighbourhood"
		switch (button)
		{
		case 0:
			return "Stage 1";
			break;
		case 1:
			return "Stage 2";
			break;
		case 2:
			return "Stage 3";
			break;
		default:
			break;
		}
		break;
	case GameScene::InStage:
		switch (dateNumber)
		{
		case GameScene::First:
			//dialog::
			getConversationButtonText(button, DateNumber::First);
			break;
		case GameScene::Second:
			getConversationButtonText(button, DateNumber::Second);
			break;
		case GameScene::Third:
			getConversationButtonText(button, DateNumber::Third);
			break;
		default:
			break;
		}
		break;
	case GameScene::HouseChoice:
		break;
	case GameScene::End:
		break;
	default:
		break;
	}
}
std::string GameScene::getConversationButtonText(int button, GameScene::DateNumber dateNumber)
{
	switch (dialogue)
	{
	case GameScene::DateIntro:
		return getCharacterAnswers(button, GameScene::DateIntro);
		break;
	case GameScene::IntroResponse:
		return getCharacterAnswers(0, GameScene::Dialogues::IntroResponse);
		break;
	case GameScene::ThisOrThat:
		return getCharacterAnswers(button, GameScene::ThisOrThat);
		break;
	case GameScene::ThisOrThatResponse:
		return getCharacterAnswers(0, GameScene::Dialogues::ThisOrThatResponse);
		break;
	case GameScene::GettingToKnowYou:
		return getCharacterAnswers(button, GameScene::GettingToKnowYou);
		break;
	case GameScene::GettingToKnowYouResponse:
		return getCharacterAnswers(0, GameScene::Dialogues::GettingToKnowYouResponse);
		break;
	case GameScene::OverallResponse:
		return getCharacterAnswers(0, GameScene::Dialogues::OverallResponse);
		break;
	default:
		break;
	}
}
void GameScene::resetButtons(int num)
{	
	switch (num)
	{
	case 0:
		buttonOne = Entity("buttonOne");

		buttonOne.addComponent(new BoxColliderComponent());
		buttonOne.addComponent(new TextComponent(fontName));
		buttonOne.addComponent(new SpriteComponent(dialBoxName));
		buttonOne.addComponent(new TransformComponent(leftPos, 0.f, buttonScale));


		static_cast<BoxColliderComponent*>(buttonOne.getComponents().at(0))->setBox(new sf::FloatRect(
			static_cast<SpriteComponent*>(buttonOne.getComponents().at(2))->getSprite()->getGlobalBounds())
		);
		static_cast<SpriteComponent*>(buttonOne.getComponents().at(2))->getSprite()->setPosition(
			static_cast<TransformComponent*>(buttonOne.getComponents().at(3))->getPosition()
		);
		boinkor.getEntities().at(0) = &buttonOne;
		lilRendo.getEntities().at(3) = &buttonOne;
		break;
	case 1:
		buttonTwo = Entity("buttonTwo");

		buttonTwo.addComponent(new BoxColliderComponent());
		buttonTwo.addComponent(new TextComponent(fontName));
		buttonTwo.addComponent(new SpriteComponent(dialBoxName));
		buttonTwo.addComponent(new TransformComponent(midPos, 0.f, buttonScale));
		static_cast<BoxColliderComponent*>(buttonTwo.getComponents().at(0))->setBox(new sf::FloatRect(
			static_cast<SpriteComponent*>(buttonTwo.getComponents().at(2))->getSprite()->getGlobalBounds())
		);
		static_cast<SpriteComponent*>(buttonTwo.getComponents().at(2))->getSprite()->setPosition(
			static_cast<TransformComponent*>(buttonTwo.getComponents().at(3))->getPosition()
		);

		lilRendo.getEntities().at(4) = &buttonTwo;
		boinkor.getEntities().at(1) = &buttonTwo;

		break;
	case 2:
		buttonThree = Entity("buttonThree");

		buttonThree.addComponent(new BoxColliderComponent());
		buttonThree.addComponent(new TextComponent(fontName));
		buttonThree.addComponent(new SpriteComponent(dialBoxName));
		buttonThree.addComponent(new TransformComponent(rightPos, 0.f, buttonScale));
		static_cast<BoxColliderComponent*>(buttonThree.getComponents().at(0))->setBox(new sf::FloatRect(
			static_cast<SpriteComponent*>(buttonThree.getComponents().at(2))->getSprite()->getGlobalBounds())
		);
		static_cast<SpriteComponent*>(buttonThree.getComponents().at(2))->getSprite()->setPosition(
			static_cast<TransformComponent*>(buttonThree.getComponents().at(3))->getPosition()
		);

		lilRendo.getEntities().at(5) = &buttonThree;
		boinkor.getEntities().at(2) = &buttonThree;

		break;
	default:
		break;
	}
	
			
			

			
			
}
std::string GameScene::getCharacterAnswers(int button, GameScene::Dialogues questionPhase)
{
	//set date to get answers stored for them
	switch (dateNumber)
	{

	case GameScene::First:
		switch (questionPhase)
		{
		case GameScene::DateIntro:
			static_cast<TextComponent*>(diallyBoi.getComponents().at(0))->getText()->setString(
				Dialog::eliseIntroQuestion
			);
			switch (button)
			{
			case 0:
				break;
			case 1:
				break;
			case 2:
				break;
			default:
				break;
			}
			break;
		case GameScene::IntroResponse:
			break;
		case GameScene::ThisOrThat:
			break;
		case GameScene::ThisOrThatResponse:
			break;
		case GameScene::GettingToKnowYou:
			break;
		case GameScene::GettingToKnowYouResponse:
			break;
		case GameScene::OverallResponse:
			break;
		default:
			break;
		}
		currentDate = &dateOne;
		break;
	case GameScene::Second:
		currentDate = &dateTwo;
		break;
	case GameScene::Third:
		currentDate = &dateThree;
		break;
	default:
		break;
	}
	switch (questionPhase)
	{
	case GameScene::Intro:
		switch (button)
		{
		case 0:
			responseStrength--;
			return""; //answer 1
			break;
		case 1:
			return""; //answer 2
			break;
		case 2:
			responseStrength++;
			return""; //answer 3
			break;
		default:
			break;
		}
		break;
	case GameScene::IntroResponse:
		return "Next Question";
		break;
	case GameScene::ThisOrThat:
		switch (button)
		{
		case 0:
			return""; //answer 1
			break;
		case 1:
			return""; //answer 2
			break;
		case 2:
			return""; //answer 3
			break;
		default:
			break;
		}
		break;
		break;
	case GameScene::ThisOrThatResponse:
		return "Next Question";
		break;
	case GameScene::GettingToKnowYou:
		switch (button)
		{
		case 0:
			return""; //answer 1
			break;
		case 1:
			return""; //answer 2
			break;
		case 2:
			return""; //answer 3
			break;
		default:
			break;
		}
		break;
	case GameScene::GettingToKnowYouResponse:
		return "Continue..";
		break;
	case GameScene::OverallResponse:
		switch (responseStrength)
		{
		case 0:
			return""; //bad
			break;
		case 1:
			return""; //neutral
			break;
		case 2:
			return""; //good
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
}
