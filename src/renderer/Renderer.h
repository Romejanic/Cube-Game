#ifndef RENDERER_RENDERER_H_
#define RENDERER_RENDERER_H_

#include "../world/World.h"
#include "WorldRenderer.h"
#include "../camera/Camera.h"
#include "Window.h"

class Renderer {
private:
	WorldRenderer worldRenderer;
	float lastFpsCheck;

public:
	void init(const World& world);
	void render(Camera camera, Window window);
	void destroy();
};

#endif
