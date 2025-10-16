#include "Map.h"


Map::Map() {
    load();
}

void Map::load() {
    MapConfig config = JsonHandler::loadMapConfig("config/map.json");
    
    tileset.loadFromFile("C:\\Users\\Hashm\\Desktop\\Coding Projects\\dungeon-redemption\\resources\\textures\\map\\walls_floor.png");
    tileSprite.setTexture(tileset);

    this->tiles = config.tiles;
    // Generate tiles
    //for (int y = 0; y < ROWS; ++y) {
    //    for (int x = 0; x < COLS; ++x) {
    //        sf::RectangleShape tile(sf::Vector2f(tileSize, tileSize));
    //        tile.setPosition(x * tileSize, y * tileSize);

    //        // Alternate colors to visualize layout
    //        if ((x + y) % 2 == 0)
    //            tile.setFillColor(sf::Color(70, 70, 70)); // dark gray
    //        else
    //            tile.setFillColor(sf::Color(100, 100, 100)); // lighter gray

    //        tiles.push_back(tile);
    //    }
    //}

    //// Generate test wall
    //sf::RectangleShape wall;
    //wall.setFillColor(sf::Color::Green);
    //wall.setSize(sf::Vector2f(50.f, 50.f));
    //wall.setPosition(50.f * 5, 50.f * 2);
    //walls.push_back(wall);
}

void Map::update(float /*deltaTime*/) {
    // optional: add animated tiles, traps, etc. later
}

void Map::draw(sf::RenderWindow& window) {

    for (int i = 0; i < tiles.size(); ++i) {
        for (int j = 0; j < tiles[i].size(); ++j) {
            char tile = tiles[i][j];

          /*  if (tile == '-') {
                tileSprite.setTextureRect(sf::IntRect(3, 9, tileSize, tileSize));
            }
            else if (tile == '|') {
                tileSprite.setTextureRect(sf::IntRect(3, 9, tileSize, tileSize));
            }
            else {
                tileSprite.setTextureRect(sf::IntRect(3, 9, tileSize, tileSize));
            }*/
            
            tileSprite.setTextureRect(sf::IntRect(2 * tileSize, 3 * tileSize, tileSize, tileSize));

            tileSprite.setPosition(j * tileSize, i * tileSize);
            window.draw(tileSprite);
        }
    }


    //for (auto& tile : tiles) {
    //    window.draw(tile);
    //}

    //for (auto& w : walls) {
    //    window.draw(w);
    //}
}


bool Map::isCollision(sf::FloatRect nextPos, sf::FloatRect playerSize) const {
    for (auto& w : walls) {

        sf::FloatRect wallBounds = w.getGlobalBounds();

        if (wallBounds.intersects(nextPos)) {
            return true;
        }
    }

    // Check if off grid
    float leftBound = tileSize * COLS - playerSize.width;
    float topBound = tileSize * ROWS - playerSize.height;
    if (nextPos.left < 0 || nextPos.left > leftBound || nextPos.top < 0 || nextPos.top > topBound) {
        return true;
    }
    return false;
}
