#include "Player.h"

Player::Player(sf::Vector2f startPos) {
	shape.setSize({ 50.f, 50.f });
	shape.setFillColor(sf::Color::Cyan);
	shape.setPosition(startPos);
}

void Player::handleInput(float deltaTimeSeconds) {
	sf::Vector2f movement(0.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) movement.y -= speed * deltaTimeSeconds;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) movement.x -= speed * deltaTimeSeconds;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) movement.x += speed * deltaTimeSeconds;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) movement.y += speed * deltaTimeSeconds;


	// Collision detection

	shape.move(movement);
}

void Player::draw(sf::RenderWindow& window) {
	window.draw(shape);
}

sf::Vector2f Player::getPosition() const {
	return shape.getPosition();
}