#include "Window.h"

bool Window::init(int w, int h, const char* title) {
	this->width  = w;
	this->height = h;
	if(!glfwInit()) {
		std::cerr << "ERR: Failed to initialize GLFW!" << std::endl;
		return false;
	}
	glfwDefaultWindowHints();
	glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
	this->win = glfwCreateWindow(this->width, this->height, title, NULL, NULL);
	if(!this->win) {
		std::cerr << "ERR: Failed to create window!" << std::endl;
		return false;
	}
	glfwMakeContextCurrent(this->win);
	glfwShowWindow(this->win);
	glfwGetFramebufferSize(this->win, &this->width, &this->height);

	return true;
}

void Window::update() {
	glfwSwapBuffers(this->win);
	glfwPollEvents();

	glfwGetFramebufferSize(this->win, &this->width, &this->height);

	double tmx, tmy;
	glfwGetCursorPos(this->win, &tmx, &tmy);
	this->mdx = (float)tmx - this->mx;
	this->mdy = (float)tmy - this->my;
	this->mx  = (float)tmx;
	this->my  = (float)tmy;

	float time  = this->getTime();
	this->delta = time - this->lastFrame;
	this->lastFrame = time;
}

void Window::destroy() {
	if(this->win) {
		glfwDestroyWindow(this->win);
	}
	glfwTerminate();
}

bool Window::hasFocus() {
	return glfwGetWindowAttrib(this->win, GLFW_FOCUSED) == GLFW_TRUE;
}

bool Window::shouldClose() {
	return glfwWindowShouldClose(this->win);
}

float Window::getTime() {
	return (float)glfwGetTime();
}

bool Window::isCursorLocked() const {
	return glfwGetInputMode(this->win, GLFW_CURSOR) == GLFW_CURSOR_DISABLED;
}

void Window::setCursorLocked(bool locked) {
	glfwSetInputMode(this->win, GLFW_CURSOR, locked ? GLFW_CURSOR_DISABLED : GLFW_CURSOR_NORMAL);
}

bool Window::isKeyDown(int code) const {
	return glfwGetKey(this->win, code) == GLFW_PRESS;
}
