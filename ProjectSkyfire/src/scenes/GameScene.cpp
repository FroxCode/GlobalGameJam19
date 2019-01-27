#include "scenes/GameScene.h"

void GameScene::initialise(std::shared_ptr<sf::RenderWindow> &window) 
{
	switch (gameState)
	{
	case GameScene::Intro:
		gameState = GameStates::Intro;
		stage = Stages::StageOne;
		dateNumber = DateNumber::First;
		dialogue = Dialogues::Intro;
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
	switch (gameState)
	{
	case GameScene::Intro:
		introUpdate(e); //swaps gameState to ChooseStage + Stage at end
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

	switch (gameState)
	{
	case GameScene::Intro:
		introRender(window); //swaps gameState to ChooseStage + Stage at end
		//show dialogue of what happens in game
		break;
	case GameScene::ChooseStage:
		choiceRender(window);
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
		stageRender(window); //Render Stage 
		break;
	case GameScene::HouseChoice:
		houseChoiceRender(window);
		break;
	case GameScene::End:
		endGameRender(window);
		break;
	default:
		goToMainMenu = true;
		break;
	}
}

void GameScene::introUpdate(sf::Event* e)
{
	boinker.update(e);

	//display intro dialogue using systems (make them)
	//checkcollision on 3 buttons jhiudwused globally in scene everychoice (less duplication)
	//if yes on one, get that number 0 1 2
}
void GameScene::introRender(std::shared_ptr<sf::RenderWindow> window)
{
	boinker.render(window);
	//display intro dialogue using systems (make them)
	//checkcollision on 3 buttons jhiudwused globally in scene everychoice (less duplication)
	//if yes on one, get that number 0 1 2
}
void GameScene::choiceUpdate()
{
	if (dummy.getId()=="") {}
}
void GameScene::stageUpdate()
{
	switch (stage)
	{
	case GameScene::StageOne:
		houseChoiceUpdate();
		break;
	case GameScene::StageTwo:
		houseChoiceUpdate();
		break;
	case GameScene::StageThree:
		houseChoiceUpdate();
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
Entity createButton(GameScene::GameStates gameState)
{

}

void GameScene::factoryRecreateButtons(int buttons = 2)//GameStates gameState, int buttons = 2)
{
	boinker = CollisionSystem();

	for(int i = 0; i < buttons; i++)
	{
		switch (i)
		{
			case 0:
				resetButtons();
				static_cast<TextComponent*>(buttonOne.getComponents().at(1))->getText()->setString(
					getButtonText(gameState, i)
				);
				boinker.addEntity(&buttonOne);
				break;
			case 1:
				resetButtons();
				static_cast<TextComponent*>(buttonOne.getComponents().at(1))->getText()->setString(
					getButtonText(gameState, i)
				);
				boinker.addEntity(&buttonOne);
				boinker.addEntity(&buttonTwo);
				break;
			case 2:
				resetButtons();
				static_cast<TextComponent*>(buttonOne.getComponents().at(1))->getText()->setString(
					getButtonText(gameState, i)
				);
				boinker.addEntity(&buttonOne);
				boinker.addEntity(&buttonTwo);
				boinker.addEntity(&buttonThree);
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
		switch (button)
		{
		case 0:
			return ""; //intro string option to go to choose stage
			break;
		default:
			break;
		}
		break;
	case GameScene::ChooseStage:
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
			switch (dialogue)
			{
			case GameScene::Dialogues::Intro:
				switch (button)
				{
				case 0:
					return getCharacterAnswers(0, GameScene::Dialogues::Intro);;
					break;
				case 1:
					return getCharacterAnswers(1, GameScene::Dialogues::Intro);;
					break;
				case 2:
					return getCharacterAnswers(2, GameScene::Dialogues::Intro);;
					break;
				default:
					break;
				}
				break;
			case GameScene::IntroResponse:
			case 0:
				return getCharacterAnswers(0, GameScene::Dialogues::IntroResponse); 
				break;
				break;
			case GameScene::ThisOrThat:
				switch (button)
				{
				case 0:
					return getCharacterAnswers(0, GameScene::ThisOrThat);
					break;
				case 1:
					return getCharacterAnswers(1, GameScene::ThisOrThat);
					break;
				case 2:
					return getCharacterAnswers(2, GameScene::ThisOrThat);
					break;
				default:
					break;
				}
				break;
			case GameScene::ThisOrThatResponse:
				break;
			case GameScene::GettingToKnowYou:
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
			case GameScene::GettingToKnowYouResponse:
				break;
			case GameScene::OverallResponse:
				break;
			default:
				break;
			}
			break;
		case GameScene::Second:
			break;
		case GameScene::Third:
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

void GameScene::resetButtons(int num = 2)
{
	switch (num)
	{
		case 0:
			buttonOne = Entity("buttonOne");
			buttonOne.addComponent(new BoxColliderComponent());
			buttonOne.addComponent(new TextComponent(fontName));
			buttonOne.addComponent(new SpriteComponent(dialBoxName));
			buttonOne.addComponent(new TransformComponent(midPos, 0.f, buttonScale));
			break;
		case 1:
			buttonTwo = Entity("buttonTwo");
			buttonTwo.addComponent(new BoxColliderComponent());
			buttonTwo.addComponent(new TextComponent(fontName));
			buttonTwo.addComponent(new SpriteComponent(dialBoxName));
			buttonTwo.addComponent(new TransformComponent(midPos, 0.f, buttonScale));
			break;
		case 2:
			buttonThree = Entity("buttonThree");
			buttonThree.addComponent(new BoxColliderComponent());
			buttonThree.addComponent(new TextComponent(fontName));
			buttonThree.addComponent(new SpriteComponent(dialBoxName));
			buttonThree.addComponent(new TransformComponent(midPos, 0.f, buttonScale));
			break;	
		default:
			break;
	}	
}
std::string GameScene::getCharacterAnswers(int button, GameScene::Dialogues questionPhase)
{
	switch (questionPhase)
	{
	case GameScene::Intro:
		switch (button)
		{
		case 0:
			responseStrength--;
			return; //answer 1
			break;
		case 1:
			return; //answer 2
			break;
		case 2:
			responseStrength++;
			return; //answer 3
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
			return; //answer 1
			break;
		case 1:
			return; //answer 2
			break;
		case 2:
			return; //answer 3
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
			return; //answer 1
			break;
		case 1:
			return; //answer 2
			break;
		case 2:
			return; //answer 3
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
			return; //bad
			break;
		case 1:
			return; //neutral
			break;
		case 2:
			return; //good
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
}
