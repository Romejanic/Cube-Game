#include "WorldRenderer.h"
#include <iostream>

void WorldRenderer::init(const World& world) {
	this->world   = world;
	this->xChunks = world.getWidth() / CHUNK_WIDTH;
	this->zChunks = world.getDepth() / CHUNK_DEPTH;

	for(int x = 0; x < this->xChunks; x++) {
		for(int z = 0; z < this->zChunks; z++) {
			Chunk chunk; chunk.init(x, z, world);
			this->chunks.push_back(chunk);
		}
	}

	this->shader = Shader::load("terrain");
	glEnable(GL_PROGRAM_POINT_SIZE);
}

void WorldRenderer::render(Camera camera) {
	this->shader.bind();
	glUniformMatrix4fv(this->shader.getUniformLocation("projMat"), 1, GL_FALSE, glm::value_ptr(camera.getProjectionMatrix()));
	glUniformMatrix4fv(this->shader.getUniformLocation("viewMat"), 1, GL_FALSE, glm::value_ptr(camera.getViewMatrix()));
	for(int i = 0; i < this->chunks.size(); i++) {
		Chunk chunk = this->chunks[i];
		chunk.render();
	}
	this->shader.unbind();
}



void WorldRenderer::destroy() {
	for(int i = 0; i < this->chunks.size(); i++) {
		this->chunks[i].destroy();
	}
}

void WorldRenderer::printChunkUpdates() {
	std::cout << Chunk::chunkUpdates << " chunk updates" << std::endl;
	Chunk::chunkUpdates = 0;
}
