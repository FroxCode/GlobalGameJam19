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
		choiceRender();
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
		stageRender(); //Render Stage 
		break;
	case GameScene::HouseChoice:
		houseChoiceRender();
		break;
	case GameScene::End:
		endGameRender();
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
	buttonTwo = createButton(GameStates::Intro);
	boinker = new CollisionSystem();
	boinker.addEntity(buttonOne);

}
void GameScene::factoryRecreateButtons(GameStates gameState, int buttons = 2)
{
	boinker = new CollisionSystem();

	for(int i = 0; i < buttons; i++)
	{
		switch (i)
		{
			case 0:
			resetButtons(0);
					static_cast<TextComponent*>(buttonOne.getComponents().at(1))->getText().setString(
						getButtonText(gameState)
					);
					boinker.addEntity(&buttonOne)
				break;
			case 1:
				break;
			case 2:
				break;
			default:
				break;
		}
	}
	
}
void resetButtons(int num)
{
	switch num)
	{
		case 0:
			buttonOne = new Entity();
			buttonOne.addComponent(new BoxColliderComponent());
			buttonOne.addComponent(new TextComponent(fontName));
			buttonOne.addComponent(new SpriteComponent(dialBoxName));
			buttonOne.addComponent(new TransformComponent(midPos, 0.f, buttonScale));
			break;
	
		default:
			break;
	}	
}