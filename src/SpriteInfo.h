#include <string>
#include <SFML/Graphics.hpp>

struct SpriteInfo {
	std::string filePath;
	sf::IntRect visibleRect;
	float scale;
};