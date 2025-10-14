#pragma once
#include <SFML/Graphics.hpp>
#include "Map.h"
#include "Animation.h"
#include "Orientation.h"
#include "data/JsonHandler.h"

class Player {
public:
	Player(sf::Vector2f startPos);
	void draw(sf::RenderWindow& window);
	sf::Vector2f getPosition() const;
	void handleInput(float deltaTimeSeconds, const Map& map);
	sf::FloatRect getPlayerSize();
	void updateAnimation(float deltaTimeSeconds);
	void updateOrientation(Orientation orientation);
private:
	float speed = 200.f;
	sf::Sprite sprite;
	Orientation orientation = Orientation::Front;
	std::unordered_map<Orientation, sf::Texture> textures;
	std::unordered_map<Orientation, Animation> animations;
};