#include "Game.h"

Game::Game() : 
	window(sf::VideoMode(500, 500), "Dungeon Redemption"), 
	view(sf::FloatRect(0.f, 0.f, 500.f, 500.f)),
	player(sf::Vector2f(0.f, 0.f))
{
	//window.setVerticalSyncEnabled(true);
}

void Game::run() {
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
		if (event.type == sf::Event::Closed) {
			window.close();
		}
	}
}

void Game::update(float deltaTimeSeconds) {
	player.handleInput(deltaTimeSeconds);
	view.setCenter(player.getPosition());
	window.setView(view);
}

void Game::render() {
	window.clear();
	map.draw(window);
	player.draw(window);
	wall.draw(window);
	window.display();
}