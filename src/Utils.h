#ifndef UTILS_H_
#define UTILS_H_

#include <string>
#include <glm/vec3.hpp>

class Utils {
public:
	static glm::vec3 UP;

	static std::string readFile(const char* path);
	static std::string readFile(std::string path);
};

#endif
