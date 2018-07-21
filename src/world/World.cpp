#include "World.h"
#include "Block.h"

void World::init(int width, int height, int depth) {
	this->width = width;
	this->height = height;
	this->depth = depth;
	this->blockCount = width * height * depth;
	this->blocks = new char[this->blockCount];

	this->generate();
}

void World::generate() {
	int seaLevel = this->height / 2;
	for(int x = 0; x < this->width; x++) {
		for(int y = 0; y < this->height; y++) {
			for(int z = 0; z < this->depth; z++) {
				if(y <= seaLevel) {
					this->setBlock(x, y, z, 1);
				} else {
					this->setBlock(x, y, z, 0);
				}
			}
		}
	}
}

char World::getBlock(int x, int y, int z) const {
	int idx = this->getBlockIndex(x, y, z);
	if(idx < 0) {
		return 0;
	}
	return this->blocks[idx];
}

void World::setBlock(int x, int y, int z, char id) {
	int idx = this->getBlockIndex(x, y, z);
	if(idx < 0) {
		return;
	}
	this->blocks[idx] = id;
}

int World::getBlockIndex(int x, int y, int z) const {
	if(x < 0 || y < 0 || z < 0 || x >= this->width || y >= this->height || z >= this->depth) {
		return -1;
	}
	int idx = (z * this->width * this->height) + (y * this->width) + x;
	if(idx < 0 || idx >= this->blockCount) {
		return -1;
	}
	return idx;
}

bool World::isBlockAir(int x, int y, int z) const {
	return this->getBlock(x, y, z) == 0;
}
