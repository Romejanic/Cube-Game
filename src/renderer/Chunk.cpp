#include "Chunk.h"
#include <iostream>
#include <vector>

int Chunk::chunkUpdates = 0;

void Chunk::init(int x, int z, const World& world) {
	this->x = x;
	this->z = z;
	this->vao = 0;
	this->vbo = 0;
	this->elementCount = 0;

	glGenVertexArrays(1, &this->vao);
	glGenBuffers(1, &this->vbo);
	this->generateMesh(world);
}

void Chunk::generateMesh(const World& world) {
	std::vector<float> geometry;
	for(int ox = 0; ox < CHUNK_WIDTH; ox++) {
		for(int y = 0; y < world.getHeight(); y++) {
			for(int oz = 0; oz < CHUNK_DEPTH; oz++) {
				int x = this->x * CHUNK_WIDTH + ox;
				int z = this->z * CHUNK_DEPTH + oz;
				if(!world.isBlockAir(x, y, z)) {
					Block* block = Block::blocks[(int)world.getBlock(x, y, z) - 1];
					block->generateGeometry(world, &geometry, x, y, z);
				}
			}
		}
	}

	glBindVertexArray(this->vao);
	glBindBuffer(GL_ARRAY_BUFFER, this->vbo);
	glBufferData(GL_ARRAY_BUFFER, 3 * sizeof(float), &geometry[0], GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	this->elementCount = geometry.size() / 3;
	Chunk::chunkUpdates++;
}

void Chunk::render() {
	glBindVertexArray(this->vao);
	glEnableVertexAttribArray(0);

	glDrawArrays(GL_POINTS, 0, this->elementCount);

	glDisableVertexAttribArray(0);
	glBindVertexArray(0);
}

void Chunk::destroy() {
	glDeleteVertexArrays(1, &this->vao);
	glDeleteBuffers(1, &this->vbo);
}
