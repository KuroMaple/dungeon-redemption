#include "Game.h"
#include <iostream>
#include <filesystem>

Game::Game() : 
	window(sf::VideoMode(500, 500), "Dungeon Redemption"), 
	view(sf::Vector2f(0.f, 0.f), sf::Vector2f(500.f, 500.f)),
	player(sf::Vector2f(0.f, 0.f))
{

}

void Game::run() {
	// Debugging, used to get the file path of the build 
	// std::cout << std::filesystem::current_path() << std::endl;

	sf::Clock clock;
	while (window.isOpen()) {
		float deltaTimeSeconds = clock.restart().asSeconds();
		processEvents();
		update(deltaTimeSeconds);
		render();
	}
}

void Game::processEvents() {
	sf::Event event;
	while (window.pollEvent(event)) {
		switch (event.type)
		{
		case sf::Event::Closed:
			window.close();
			break;
		case sf::Event::Resized:
			view.setSize(event.size.width, event.size.height);
			break;
		default:
			break;
		}
	}
}

void Game::update(float deltaTimeSeconds) {
	player.updateAnimation(deltaTimeSeconds);
	player.handleInput(deltaTimeSeconds, map);
	view.setCenter(player.getPosition());
	window.setView(view);
}

void Game::render() {
	window.clear();
	map.draw(window);
	player.draw(window);
	window.display();
}
