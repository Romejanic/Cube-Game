#ifndef RENDERER_WORLDRENDERER_H_
#define RENDERER_WORLDRENDERER_H_

#include <vector>
#include <glm/gtc/type_ptr.hpp>

#include "Chunk.h"
#include "../gl/Shader.h"
#include "../world/World.h"
#include "../camera/Camera.h"

class WorldRenderer {
private:
	int xChunks, zChunks;
	World world;
	Shader shader;
	std::vector<Chunk> chunks;

public:
	void init(World world);
	void render(Camera camera);
	void destroy();

	static void printChunkUpdates();
};

#endif
