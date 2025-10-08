#include "Map.h"

Map::Map() {
    load();
}

void Map::load() {
    // Example: generate a 10x10 grid of tiles
    const int rows = 10;
    const int cols = 10;
    const float tileSize = 50.f;
    
    // Generate tiles
    for (int y = 0; y < rows; ++y) {
        for (int x = 0; x < cols; ++x) {
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

    // Generate walls
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

bool Map::isBlocked(sf::FloatRect nextPos) const {
    for (auto& w : walls) {

        sf::FloatRect wallBounds = w.getGlobalBounds();

        if (wallBounds.intersects(nextPos)) {
            return true;
        }
    }
    return false;
}
