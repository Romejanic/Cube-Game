#include <cmath>
#include "Camera.h"
#include "../Utils.h"

Camera::Camera(float x, float y, float z) {
	this->position = vec3(x, y, z);
	this->rotation = vec3(0, 0, 0);

	this->moveSpeed = 5.0f;
	this->rotSpeed  = 45.0f;

	this->fov  = 70.0f;
	this->near = 0.1f;
	this->far  = 1000.0f;
}

void Camera::update(const Window& window, int w, int h) {
	if(!window.isCursorLocked()) {
		return;
	}

	float rotSpeed    = this->rotSpeed * 0.5f * window.getDelta();
	this->rotation.x += window.getMouseDY() * rotSpeed;
	this->rotation.y += window.getMouseDX() * rotSpeed;
	this->rotation.x  = clamp(this->rotation.x, -89.0f, 89.0f);

	float sinX = std::sin(radians(this->rotation.x));
	float cosX = std::cos(radians(this->rotation.x));
	float sinY = std::sin(radians(this->rotation.y));
	float cosY = std::cos(radians(this->rotation.y));

	this->forward.x = sinY * cosX;
	this->forward.y = -sinX;
	this->forward.z = cosY * -cosX;
	this->forward   = normalize(this->forward);

	float moveSpeed = this->moveSpeed * window.getDelta();
	if(window.isKeyDown(KEY_LSHIFT)) {
		moveSpeed *= 2.0f;
	}
	if(window.isKeyDown(KEY_W)) {
		this->position += this->forward * moveSpeed;
	}
	if(window.isKeyDown(KEY_S)) {
		this->position -= this->forward * moveSpeed;
	}

	float sinY90 = std::sin(radians(this->rotation.y + 90.0f)) * moveSpeed;
	float cosY90 = std::cos(radians(this->rotation.y + 90.0f)) * moveSpeed;
	if(window.isKeyDown(KEY_A)) {
		this->position.x -= sinY90;
		this->position.z += cosY90;
	}
	if(window.isKeyDown(KEY_D)) {
		this->position.x += sinY90;
		this->position.z -= cosY90;
	}

	float aspect  = (float)w / (float)h;
	this->projMat = perspective(radians(this->fov), aspect, this->near, this->far);
	this->viewMat = lookAt(this->position, this->position + this->forward, Utils::UP);
}
