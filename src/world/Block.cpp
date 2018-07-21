#include <iostream>
#include "Block.h"

Block* Block::blocks[256] = {
	new Block(1, "stone")
};

Block::Block(char id, std::string name) {
	this->id = id;
	this->name = name;
}

void Block::generateGeometry(World world, std::vector<float>* vertices, int x, int y, int z) {
	vertices->push_back(x);
	vertices->push_back(y);
	vertices->push_back(z);
}
