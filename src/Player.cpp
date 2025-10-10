#include "Player.h"
#include <iostream>

Player::Player(sf::Vector2f startPos) {

	texture.loadFromFile("../../../resources/player_idle_front/Swordsman_lvl3_Idle_front1.png");
	sprite.setTexture(texture);
	sprite.scale(sf::Vector2f(2.f, 2.f));
	sprite.setPosition(startPos);
}

void Player::draw(sf::RenderWindow& window) {
	window.draw(sprite);
}

sf::Vector2f Player::getPosition() const {
	return sprite.getPosition();
}

void Player::handleInput(float deltaTimeSeconds, const Map& map) {


	sf::Vector2f movement(0.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) movement.y -= speed * deltaTimeSeconds;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) movement.x -= speed * deltaTimeSeconds;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) movement.x += speed * deltaTimeSeconds;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) movement.y += speed * deltaTimeSeconds;

	// Collisions
	sf::FloatRect playerBounds = sprite.getGlobalBounds();
	sf::FloatRect nextPos;
	nextPos = playerBounds;
	nextPos.left += movement.x;
	nextPos.top += movement.y;

	if (map.isCollision(nextPos, getPlayerSize())) {
		std::cout << "COLLISION" << "\n";
		return; // return early and dont draw
	}

	sprite.move(movement);
}

float Player::getPlayerSize() {
	return size;
}