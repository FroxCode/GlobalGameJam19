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
		introUpdate(); //swaps gameState to ChooseStage + Stage#
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

}

void GameScene::introUpdate()
{

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