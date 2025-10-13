#include "Player.h"
#include <iostream>
#include "data/JsonHandler.h"


Player::Player(sf::Vector2f startPos) {
	PlayerConfig config = JsonHandler::loadPlayerConfig("config/player.json");

	texture.loadFromFile(config.texturePath);
	sprite.setTexture(texture);
	// animation
	this->animation = Animation(&texture, sf::Vector2u(12, 1), 0.3f);

	
	//sprite.setTextureRect(sf::IntRect(textureSize.x * 0, textureSize.y * 0, textureSize.x, textureSize.y));
	sprite.scale(config.scale, config.scale);
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
		//std::cout << "COLLISION" << "\n";
		return; // return early and dont draw
	}

	sprite.move(movement);
}

sf::Vector2u Player::getPlayerSize() {
	auto size = texture.getSize();
	size.x /= 12;
	return size;
}

void Player::updateAnimation(float deltaTimeSeconds) {
	this->animation.Update(0, deltaTimeSeconds);
	this->sprite.setTextureRect(animation.uvRect);
}