#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class Tilemap: public sf::Drawable, public sf::Transformable {
private:
	sf::VertexArray m_vertices;
	sf::Texture m_tileset;
	std::vector<sf::Text> tileLabels;
	sf::Font font;
public:
	bool load(const std::string& tileset, 
		sf::Vector2u tileSize, 
		const int* tiles, 
		unsigned int width, 
		unsigned int height);
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};