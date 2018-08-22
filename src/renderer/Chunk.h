#ifndef RENDERER_CHUNK_H_
#define RENDERER_CHUNK_H_

#include "../gl.h"
#include "../world/World.h"
#include "../world/Block.h"

#define CHUNK_WIDTH 16
#define CHUNK_DEPTH 16

class Chunk {
private:
	int x, z;

	GLuint vao;
	GLuint vbo;
	int elementCount;

public:
	static int chunkUpdates;

	void init(int x, int z, const World& world);
	int getX() const { return x; }
	int getZ() const { return z; }

	void generateMesh(const World& world);
	void render();
	void destroy();
};

#endif
