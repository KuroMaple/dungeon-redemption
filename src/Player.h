#pragma once
#include <SFML/Graphics.hpp>

class Player {
public:
	Player(sf::Vector2f startPos);
	void handleInput(float deltaTimeSeconds);
	void draw(sf::RenderWindow& window);
	sf::Vector2f getPosition() const;

private:
	sf::RectangleShape shape;
	float speed = 200.f;
};