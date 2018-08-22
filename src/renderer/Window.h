#ifndef RENDERER_WINDOW_H_
#define RENDERER_WINDOW_H_

#include <iostream>

class GLFWwindow;

class Window {
private:
	GLFWwindow* win;
	int width, height;

	float delta;
	float lastFrame;
	float mx, my, mdx, mdy;

public:
	bool init(int w, int h, const char* title);
	void update();
	void destroy();

	int getWidth() const { return width; }
	int getHeight() const { return height; }
	bool shouldClose();
	bool hasFocus();

	float getTime();
	float getDelta() const { return delta; }

	bool isCursorLocked() const;
	void setCursorLocked(bool locked);
	float getMouseX() const { return mx; }
	float getMouseY() const { return my; }
	float getMouseDX() const { return mdx; }
	float getMouseDY() const { return mdy; }
	bool isKeyDown(int code) const;
};

#endif
