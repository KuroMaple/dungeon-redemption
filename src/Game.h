#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Map.h"
#include "Wall.h"

class Game {
public:
	Game();
	void run();

private:
	void processEvents();
	void update(float deltaTimeSeconds);
	void render();

	sf::RenderWindow window;
	sf::View view;

	Player player;
	Map map;
	Wall wall;
};