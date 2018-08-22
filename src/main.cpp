#include <iostream>

#include "renderer/Window.h"
#include "renderer/Renderer.h"
#include "world/World.h"
#include "camera/Camera.h"
#include "Utils.h"

int main() {
	Window win;
	if(!win.init(1024, 640, "Cube Game")) {
		win.destroy();
		return -1;
	}
	World world;
	Renderer renderer;
	Camera camera(0, 0, 3);

	world.init();
	renderer.init(world);

	win.setCursorLocked(true);
	while(!win.shouldClose()) {
		if(win.hasFocus()) {
			camera.update(win, win.getWidth(), win.getHeight());
			renderer.render(camera, win);
		}
		win.update();
	}

	renderer.destroy();
	win.destroy();
  world.destroy();
	return 0;
}
