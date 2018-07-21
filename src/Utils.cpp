#include <iostream>
#include <fstream>
#include <sstream>

#include "Utils.h"

glm::vec3 Utils::UP = glm::vec3(0.0f, 1.0f, 0.0f);

std::string Utils::readFile(const char* path) {
	std::fstream file;
	file.open(path);
	if(!file.is_open()) {
		std::cerr << "ERR: file could not be opened: " << path << std::endl;
		return NULL;
	}
	std::stringstream out;
	std::string ln;
	while(!file.eof()) {
		std::getline(file, ln);
		out << ln << std::endl;
	}
	file.close();
	return out.str();
}

std::string Utils::readFile(std::string path) {
	return Utils::readFile(path.c_str());
}
