#include "Game.h"
#include <iostream>

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
	handleInput(deltaTimeSeconds);
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

void Game::handleInput(float deltaTimeSeconds) {
	

	sf::Vector2f movement(0.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) movement.y -= player.speed * deltaTimeSeconds;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) movement.x -= player.speed * deltaTimeSeconds;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) movement.x += player.speed * deltaTimeSeconds;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) movement.y += player.speed * deltaTimeSeconds;

	// Collisions
	sf::FloatRect nextPos;
	for (auto& w : wall.walls) {
		sf::FloatRect playerBounds = player.shape.getGlobalBounds();
		sf::FloatRect wallBounds = w.getGlobalBounds();
		nextPos = playerBounds;
		nextPos.left += movement.x;
		nextPos.top += movement.y;
		if (wallBounds.intersects(nextPos)) {
			std::cout << "COLLISION" << "\n";
			return; // return early and dont draw
		}
		
	}


	player.shape.move(movement);
}