#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <vector>

using namespace std;

struct MapConfig {
	string name;
	int width;
	int height;
	vector<string> tiles;
	string texturePath;
	unordered_map<char, sf::Texture> tileMap;
};