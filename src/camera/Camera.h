#ifndef CAMERA_CAMERA_H_
#define CAMERA_CAMERA_H_

#include "../renderer/Window.h"
#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>

using namespace glm;

class Camera {
private:
	vec3 position;
	vec3 rotation;
	float fov;
	float near;
	float far;

	float moveSpeed;
	float rotSpeed;

	mat4 projMat;
	mat4 viewMat;
	mat4 cameraMat;
	vec3 forward;

public:
	Camera(float x, float y, float z);
	vec3 getPosition() const { return position; }
	vec3 getRotation() const { return rotation; }
	float getFOV() const { return fov; }
	float getNearPlane() const { return near; }
	float getFarPlane() const { return far; }

	mat4 getProjectionMatrix() const { return projMat; }
	mat4 getViewMatrix() const { return viewMat; }
	mat4 getProjectionViewMatrix() const { return cameraMat; }

	void update(const Window& window, int w, int h);
};

#endif
