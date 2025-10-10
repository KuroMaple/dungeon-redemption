#include "Player.h"
#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>

Player::Player(sf::Vector2f startPos) {
	// Reading texture config info from file

	std::ifstream f(std::string(RESOURCES_PATH) + "config/player.json");
	nlohmann::json data;
	f >> data;

	auto idleFront1 = data["animations"]["idle_front1"];
	std::string texturePath = std::string(RESOURCES_PATH) + idleFront1["path"].get<std::string>();
	
	std::vector<int> recVals = idleFront1["rect"].get<std::vector<int>>();
	sf::IntRect visibleRect(
		recVals[0],
		recVals[1],
		recVals[2],
		recVals[3]
	);

	texture.loadFromFile(texturePath);
	sprite.setTexture(texture);
	sprite.setTextureRect(visibleRect);
	float size = data["scale"].get<float>();
	sprite.scale(size, size);
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

sf::Vector2u Player::getPlayerSize() {
	auto size = texture.getSize();
	std::cout << "player size is x: " << size.x << " y: " << size.y << "\n";
	return size;
}