//Created by Dale Sinnott
#include "scenes/MenuScene.h"

MenuScene::MenuScene(std::string name) :
	Scene(name),
	backgroundImage("backgroundImage"),
	playButton("playButton")
{

}

void MenuScene::initialise(std::shared_ptr<sf::RenderWindow> window)
{
	boinker.addWindow(window);
	backgroundImage.addComponent(new SpriteComponent(backgroundImagePath));
	backgroundImage.addComponent(new TransformComponent());

	playButton.addComponent(new SpriteComponent(playButtonImagePath));
	playButton.addComponent(new TransformComponent(sf::Vector2f(1320, 480)));
	playButton.addComponent(new BoxColliderComponent());
	static_cast<SpriteComponent*>(playButton.getComponents().at(0))->getSprite()->setPosition(
		static_cast<TransformComponent*>(playButton.getComponents().at(1))->getPosition()
	);
	
	static_cast<BoxColliderComponent*>(playButton.getComponents().at(2))->setBox(new sf::FloatRect(
		static_cast<SpriteComponent*>(playButton.getComponents().at(0))->getSprite()->getGlobalBounds())
	);

	lilRendy.addEntity(&backgroundImage);
	lilRendy.addEntity(&playButton);

	boinker.addEntity(&playButton);
}
void MenuScene::update(sf::Event* e)
{
	boinker.update();
}
void MenuScene::render(std::shared_ptr<sf::RenderWindow> &window)
{
	lilRendy.update(window);
}
