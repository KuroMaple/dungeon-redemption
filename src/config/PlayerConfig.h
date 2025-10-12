#include <string>
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <vector>

using namespace std;

struct PlayerConfig {
	string name;
	string texturePath;
	float scale;
	unordered_map<string, string> animations;
	vector<int> recVals;
};