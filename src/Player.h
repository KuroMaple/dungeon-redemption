#pragma once
#include <SFML/Graphics.hpp>
#include "Map.h"

class Player {
public:
	Player(sf::Vector2f startPos);
	void draw(sf::RenderWindow& window);
	sf::Vector2f getPosition() const;
	void handleInput(float deltaTimeSeconds, const Map& map);
	float getPlayerSize();

private:
	float speed = 200.f;
	float size = 50.f;
	sf::RectangleShape shape;

};