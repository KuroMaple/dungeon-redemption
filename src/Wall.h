#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Wall {
public:
    Wall();
    void draw(sf::RenderWindow& window);

private:
    std::vector<sf::RectangleShape> walls;
};
