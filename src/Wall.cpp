#include "Wall.h"

Wall::Wall() {
	sf::RectangleShape wall;
	wall.setFillColor(sf::Color::Green);
	wall.setSize(sf::Vector2f(50.f, 50.f));
	wall.setPosition(50.f * 5, 50.f * 2);
	walls.push_back(wall);
}

void Wall::draw(sf::RenderWindow& window) {
	for (auto& w : walls) {
		window.draw(w);
	}
}