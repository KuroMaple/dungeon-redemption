#include <string>
#include "../config/PlayerConfig.h"
class JsonHandler {
public:
	static PlayerConfig loadPlayerConfig(const std::string& resourcePath);
};