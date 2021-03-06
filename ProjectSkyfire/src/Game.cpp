////////////////////////////////////////////////////////////
//
// Game.cpp
// Created by Dale Sinnott
// 17/12/2018
//
////////////////////////////////////////////////////////////
#include "Game.h"
Game::Game() :
	defaultResolution(highRes)
{
	window = std::make_shared<sf::RenderWindow>(sf::VideoMode(defaultResolution.x, defaultResolution.y), "House Seducing Simulator 2019");
	window->clear();
	window->display();
}

Game::~Game()
{

}

///Game loop
void Game::run()
{
	initialize();	
	sf::Event event;
	FPS_clock.restart();
	sf::Int32 FPS_previous = FPS_clock.getElapsedTime().asMilliseconds();
	sf::Int32 FPS_lag = 0;
	while (isRunning)
	{
		sf::Int32 FPS_current = FPS_clock.getElapsedTime().asMilliseconds();
		sf::Int32 FPS_elapsed = FPS_current - FPS_previous;
		FPS_previous = FPS_current;
		FPS_lag += FPS_elapsed;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				isRunning = false;
			}
			if (event.type == sf::Event::KeyReleased)
			{
				switch (event.key.code)
				{
				case sf::Keyboard::Escape:
					isRunning = false;
					break;
				default:
					break;
				}
			}
		}
		while(FPS_lag >= MS_PER_UPDATE)
		{
			fixedUpdate(&event);
			
			FPS_lag -= MS_PER_UPDATE;
		}
		render(); ///here lag could be passed to advance physics just before rendering (normalized: lag/ms per update: shows objects moving between frames at %speed of progress towards next frame)
	}
	std::cout << "Closing...";
}
void Game::initialize()
{
	std::cout << "initializing" << std::endl;
	sceneManager.initialise(window);
}
void Game::fixedUpdate(sf::Event* e)
{
	///std::cout << "updating (fixed)" << std::endl;
	sceneManager.fixedUpdate(e);

}
void Game::render()
{
	///std::cout << "rendering" << std::endl;
	///TODO: update physics before rendering at % towards next fixed update
	window->clear(sf::Color::Black);

	///Draw in here
	sceneManager.render(window);

	window->display();
}
