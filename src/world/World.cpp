#include "World.h"
#include "Block.h"

void World::init() {
	this->generate();
}

void World::generate() {
	int seaLevel = wHeight / 2;
	for(int x = 0; x < wWidth; x++) {
		for(int y = 0; y < wHeight; y++) {
			for(int z = 0; z < wDepth; z++) {
				if(y <= seaLevel) {
					this->blocks[x][y][z] = 1;
				} else {
					this->blocks[x][y][z] = 0;
				}
			}
		}
	}
}

void World::destroy() {
  //delete [] blocks;
}
