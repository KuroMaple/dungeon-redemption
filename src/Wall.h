#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Wall {
public:
    Wall();
    void draw(sf::RenderWindow& window);
    std::vector<sf::RectangleShape> walls;

private:
    
};
