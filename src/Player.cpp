#include "Player.h"
#include <iostream>

Player::Player(sf::Vector2f startPos) {
	shape.setSize({ 50.f, 50.f });
	shape.setFillColor(sf::Color::Cyan);
	shape.setPosition(startPos);
}

void Player::draw(sf::RenderWindow& window) {
	window.draw(shape);
}

sf::Vector2f Player::getPosition() const {
	return shape.getPosition();
}

void Player::handleInput(float deltaTimeSeconds, const Map& map) {


	sf::Vector2f movement(0.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) movement.y -= speed * deltaTimeSeconds;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) movement.x -= speed * deltaTimeSeconds;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) movement.x += speed * deltaTimeSeconds;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) movement.y += speed * deltaTimeSeconds;

	// Collisions
	sf::FloatRect playerBounds = shape.getGlobalBounds();
	sf::FloatRect nextPos;
	nextPos = playerBounds;
	nextPos.left += movement.x;
	nextPos.top += movement.y;

	if (map.isBlocked(nextPos)) {
		std::cout << "COLLISION" << "\n";
		return; // return early and dont draw
	}


	shape.move(movement);
}