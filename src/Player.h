#pragma once
#include <SFML/Graphics.hpp>
#include "Map.h"
#include "Animation.h"

class Player {
public:
	Player(sf::Vector2f startPos);
	void draw(sf::RenderWindow& window);
	sf::Vector2f getPosition() const;
	void handleInput(float deltaTimeSeconds, const Map& map);
	sf::Vector2u getPlayerSize();
	void updateAnimation(float deltaTimeSeconds);

private:
	float speed = 200.f;
	sf::Texture texture;
	sf::Sprite sprite;
	Animation animation;
};