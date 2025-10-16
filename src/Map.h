#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "MapConfig.h"
#include "data/JsonHandler.h"
#include <string>

class Map {
public:
    Map();

    void load();
    void update(float deltaTime);
    void draw(sf::RenderWindow& window);
    bool isCollision(sf::FloatRect nextPos, sf::FloatRect playerSize) const;

private:
    std::vector<std::string> tiles;
    std::vector<sf::RectangleShape> walls;
    int COLS = 10;
    int ROWS = 10;
    float tileSize = 32.f;
    sf::Texture tileset;
    sf::Sprite tileSprite;
};
