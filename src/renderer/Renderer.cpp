#include <iostream>
#include "Renderer.h"

void Renderer::init(const World& world) {
	glClearColor(0.4, 0.6, 0.9, 1.0);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glDepthFunc(GL_LEQUAL);
	glCullFace(GL_BACK);

	this->worldRenderer.init(world);
}

void Renderer::render(Camera camera, Window window) {
	glViewport(0, 0, window.getWidth(), window.getHeight());
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	this->worldRenderer.render(camera);

	if((window.getTime() - this->lastFpsCheck) >= 1.0) {
		this->lastFpsCheck = window.getTime();
		std::cout << (1.0/window.getDelta()) << " fps, ";
		WorldRenderer::printChunkUpdates();
	}
}

void Renderer::destroy() {
	this->worldRenderer.destroy();
}
