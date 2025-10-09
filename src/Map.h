#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Map {
public:
    Map();

    void load();
    void update(float deltaTime);
    void draw(sf::RenderWindow& window);
    bool isCollision(sf::FloatRect nextPos, float playerSize) const;

private:
    std::vector<sf::RectangleShape> tiles;
    std::vector<sf::RectangleShape> walls;
    int COLS = 10;
    int ROWS = 10;
    float tileSize = 50.f;
};
