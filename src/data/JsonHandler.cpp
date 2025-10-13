#include "JsonHandler.h"
#include <nlohmann/json.hpp>
#include <fstream>

using std::string, std::ifstream, nlohmann::json;


PlayerConfig JsonHandler::loadPlayerConfig(const string& resourcePath) {
	ifstream f(string(RESOURCES_PATH) + resourcePath);
	json data;
	f >> data;

	PlayerConfig loadedConfig;
	//loadedConfig.texturePath = string(RESOURCES_PATH) + data["animations"]["idle_front1"]["path"].get<std::string>();
	//loadedConfig.recVals = data["animations"]["idle_front1"]["rect"].get<std::vector<int>>();

	loadedConfig.texturePath = string(RESOURCES_PATH) + data["location"].get<std::string>();


	loadedConfig.scale = data["scale"].get<float>();
	
	return loadedConfig;
}