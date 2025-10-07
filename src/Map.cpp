#include "Map.h"

Map::Map() {
    load();
}

void Map::load() {
    // Example: generate a 10x10 grid of tiles
    const int rows = 10;
    const int cols = 10;
    const float tileSize = 50.f;

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
}

void Map::update(float /*deltaTime*/) {
    // optional: add animated tiles, traps, etc. later
}

void Map::draw(sf::RenderWindow& window) {
    for (auto& tile : tiles) {
        window.draw(tile);
    }
}
