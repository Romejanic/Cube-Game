#ifndef WORLD_BLOCK_H_
#define WORLD_BLOCK_H_

#include <string>
#include <vector>

#include "World.h"

class Block {
private:
	char id;
	std::string name;

	Block(char id, std::string name);

public:
	static Block* blocks[256];

	char getID() const { return id; }
	std::string getName() const { return name; }

	void generateGeometry(const World& world, std::vector<float>* vertices, int x, int y, int z);
};

#endif
