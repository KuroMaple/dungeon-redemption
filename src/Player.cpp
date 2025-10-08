#include "Player.h"

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