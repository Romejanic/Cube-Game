#ifndef WORLD_WORLD_H_
#define WORLD_WORLD_H_

#include <cassert>

constexpr int wWidth  = 256;
constexpr int wHeight = 256;
constexpr int wDepth  = 256;

class World {
private:
	char blocks[wWidth][wHeight][wDepth];

	// debug only
	void checkBlockBounds(int x, int y, int z) const {
		assert(x >= 0);
		assert(y >= 0);
		assert(z >= 0);
		assert(x < wWidth);
		assert(y < wHeight);
		assert(z < wDepth);
	};

public:
  World() {}

  // Disallow copy.
  World(const World&) = delete;
  World& operator=(const World&) = delete;

	void init();
	void generate();
  	void destroy();
	// these are kinda pointless now, leaving them so i don't break anything
	// probably should be removed later
	int getWidth() const { return wWidth; }
	int getHeight() const { return wHeight; }
	int getDepth() const { return wDepth; }

	char getBlock(int x, int y, int z) const {
	 	checkBlockBounds(x, y, z);
		return blocks[x][y][z];	
	};
	void setBlock(int x, int y, int z, char id) {
	 	checkBlockBounds(x, y, z);
		blocks[x][y][z] = id;
	};
	bool isBlockAir(int x, int y, int z) const {
		return getBlock(x, y, z) == 0;	
	};
};

#endif
