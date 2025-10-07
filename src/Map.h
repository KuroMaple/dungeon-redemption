#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Map {
public:
    Map();

    void load();
    void update(float deltaTime);
    void draw(sf::RenderWindow& window);

private:
    std::vector<sf::RectangleShape> tiles;
};
