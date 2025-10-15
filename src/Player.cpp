#include "Player.h"


using namespace std;

Player::Player(sf::Vector2f startPos) {
	PlayerConfig config = JsonHandler::loadPlayerConfig("config/player.json");

	// Loading textures from files
	this->textures[Orientation::Front].loadFromFile(config.frontTexturePath);
	this->textures[Orientation::Right].loadFromFile(config.rightTexturePath);
	this->textures[Orientation::Back].loadFromFile(config.backTexturePath);
	this->textures[Orientation::Left].loadFromFile(config.leftTexturePath);

	// Set animations 
	this->animations[Orientation::Front] = Animation(&this->textures[Orientation::Front], sf::Vector2u(12, 1), 0.3f);
	this->animations[Orientation::Right] = Animation(&this->textures[Orientation::Right], sf::Vector2u(12, 1), 0.3f);
	this->animations[Orientation::Back] = Animation(&this->textures[Orientation::Back], sf::Vector2u(4, 1), 0.3f);
	this->animations[Orientation::Left] = Animation(&this->textures[Orientation::Left], sf::Vector2u(12, 1), 0.3f);

	sprite.setTexture(this->textures[orientation]);
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
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) { 
		movement.y -= speed * deltaTimeSeconds; 
		updateOrientation(Orientation::Back);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		movement.x -= speed * deltaTimeSeconds;
		updateOrientation(Orientation::Left);
	} 
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) { 
		movement.x += speed * deltaTimeSeconds;
		updateOrientation(Orientation::Right);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) { 
		movement.y += speed * deltaTimeSeconds;
		updateOrientation(Orientation::Front);
	}

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

sf::FloatRect Player::getPlayerSize() {
	auto size = sprite.getGlobalBounds();
	return size;
}

void Player::updateAnimation(float deltaTimeSeconds) {
	this->animations[this->orientation].Update(0, deltaTimeSeconds);
	this->sprite.setTextureRect(animations[this->orientation].uvRect);
}

void Player::updateOrientation(Orientation orientation) {
	this->orientation = orientation;
	sprite.setTexture(this->textures[this->orientation]);
}

