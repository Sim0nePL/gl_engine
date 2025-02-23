#pragma once

#define GLM_ENABLE_EXPERIMENTAL

#include "glad/gl.h"
#include <GLFW/glfw3.h>
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "glm/gtx/rotate_vector.hpp"

#include "Shader.h"

class Camera {
public:
	Camera(int width, int height, glm::vec3 position);
	~Camera();

	void Matrix(Shader& shader, const char* uniform);
	void Inputs(GLFWwindow* window);

	// Display Settings
	int width;
	int height;

	float fov = 60;

	// Camera Control variables
	float speed = 0.1f;
	float sensitivity = 100.0f;

private:
	// Camera Object Properties
	glm::vec3 Position;
	glm::vec3 Orientation { 0.0f, 0.0f, -1.0f };
	glm::vec3 Up { 0.0f, 1.0f, 0.0f };

	float nearPlane = 0.1f;
	float farPlane = 100.0f;
};

