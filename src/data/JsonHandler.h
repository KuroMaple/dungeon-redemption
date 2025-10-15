#pragma once
#include <string>
#include "MapConfig.h"
#include "PlayerConfig.h"

class JsonHandler {
public:
	static PlayerConfig loadPlayerConfig(const std::string& resourcePath);
	static MapConfig loadMapConfig(const std::string& resourcePath);
};