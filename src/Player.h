#pragma once
#include <SFML/Graphics.hpp>

class Player {
public:
	Player(sf::Vector2f startPos);
	void draw(sf::RenderWindow& window);
	sf::Vector2f getPosition() const;
	float speed = 200.f;
	sf::RectangleShape shape;

private:
	
	
};