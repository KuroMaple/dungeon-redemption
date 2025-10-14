#include <string>
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <vector>

using namespace std;

struct PlayerConfig {
	string name;
	string frontTexturePath;
	string rightTexturePath;
	string leftTexturePath;
	string backTexturePath;
	float scale;
};