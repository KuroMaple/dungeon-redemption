#include "JsonHandler.h"
#include <nlohmann/json.hpp>
#include <fstream>

using std::string, std::ifstream, nlohmann::json;


PlayerConfig JsonHandler::loadPlayerConfig(const string& resourcePath) {
	ifstream f(string(RESOURCES_PATH) + resourcePath);
	json data;
	f >> data;

	PlayerConfig loadedConfig;

	loadedConfig.frontTexturePath = string(RESOURCES_PATH) + data["IdleFront"].get<std::string>();
	loadedConfig.rightTexturePath = string(RESOURCES_PATH) + data["IdleRight"].get<std::string>();
	loadedConfig.backTexturePath = string(RESOURCES_PATH) + data["IdleBack"].get<std::string>();
	loadedConfig.leftTexturePath = string(RESOURCES_PATH) + data["IdleLeft"].get<std::string>();

	loadedConfig.name = data["name"];
	loadedConfig.scale = data["scale"].get<float>();
	
	return loadedConfig;
}