#ifndef WORLD_WORLD_H_
#define WORLD_WORLD_H_

class World {
private:
	char* blocks;
	int width, height, depth, blockCount;

public:
	void init(int width, int height, int depth);
	void generate();
  void destroy();
	int getWidth() const { return width; }
	int getHeight() const { return height; }
	int getDepth() const { return depth; }

	char getBlock(int x, int y, int z) const;
	void setBlock(int x, int y, int z, char id);
	int getBlockIndex(int x, int y, int z) const;
	bool isBlockAir(int x, int y, int z) const;
};

#endif
