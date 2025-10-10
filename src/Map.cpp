#include "Map.h"
#include <string>

Map::Map() {
    load();
}

void Map::load() {
    // Generate tiles
    for (int y = 0; y < ROWS; ++y) {
        for (int x = 0; x < COLS; ++x) {
            sf::RectangleShape tile(sf::Vector2f(tileSize, tileSize));
            tile.setPosition(x * tileSize, y * tileSize);

            // Alternate colors to visualize layout
            if ((x + y) % 2 == 0)
                tile.setFillColor(sf::Color(70, 70, 70)); // dark gray
            else
                tile.setFillColor(sf::Color(100, 100, 100)); // lighter gray

            tiles.push_back(tile);
        }
    }

    // Generate test wall
    sf::RectangleShape wall;
    wall.setFillColor(sf::Color::Green);
    wall.setSize(sf::Vector2f(50.f, 50.f));
    wall.setPosition(50.f * 5, 50.f * 2);
    walls.push_back(wall);
}

void Map::update(float /*deltaTime*/) {
    // optional: add animated tiles, traps, etc. later
}

void Map::draw(sf::RenderWindow& window) {
    for (auto& tile : tiles) {
        window.draw(tile);
    }

    for (auto& w : walls) {
        window.draw(w);
    }
}


/*
    Assumes player sprite is a sqaure
*/
bool Map::isCollision(sf::FloatRect nextPos, sf::Vector2u playerSize) const {
    for (auto& w : walls) {

        sf::FloatRect wallBounds = w.getGlobalBounds();

        if (wallBounds.intersects(nextPos)) {
            return true;
        }
    }

    // Check if off grid
    float leftBound = tileSize * COLS - playerSize.x + 25;
    float topBound = tileSize * ROWS - playerSize.y;
    if (nextPos.left < 0 || nextPos.left > leftBound || nextPos.top < 0 || nextPos.top > topBound) {
        return true;
    }
    return false;
}
