#include "Camera.h"
#include <GLFW/glfw3.h>
#include <glm/ext/matrix_transform.hpp>
#include <glm/geometric.hpp>
#include <glm/trigonometric.hpp>

Camera::Camera(int width, int height, glm::vec3 position) {
	Camera::width = width;
	Camera::height = height;
	Camera::Position = position;
}

void Camera::Matrix(Shader& shader, const char* uniform) {
	glm::mat4 view (1.0f);
	glm::mat4 projection (1.0f);

	view = glm::lookAt(Position, Position + Orientation, Up);
	projection = glm::perspective(glm::radians(fov), (float) width / height, nearPlane, farPlane);

	glUniformMatrix4fv(glGetUniformLocation(shader.GetId(), uniform), 1, false, glm::value_ptr(projection * view));
}

void Camera::Inputs(GLFWwindow* window) {
	// Keyboard
	//  - Horizontal
	if(glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) // Forward
		Position += Orientation * speed;
	if(glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) // Backward
		Position += -Orientation * speed;
	if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) // Left
		Position += glm::normalize(glm::cross(Up, Orientation)) * speed;
	if(glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) // Right
		Position += -glm::normalize(glm::cross(Up, Orientation)) * speed;

	//  - Vertical
	if(glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS) // Up
		Position += Up * speed;
	if(glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) // Down
		Position += -Up * speed;

	/* Just dont.
	if(glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS) // Right
		Up = glm::rotate(Up, glm::radians(1.0f), Orientation);
	if(glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS) // Right
		Up = glm::rotate(Up, glm::radians(-1.0f), Orientation);
	*/

	// Mouse
	if(glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_1) == GLFW_PRESS) {
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

		if(glfwGetInputMode(window, GLFW_CURSOR) == GLFW_CURSOR_DISABLED) {
			double mouseX, mouseY;
			glfwGetCursorPos(window, &mouseX, &mouseY);

			float rotX = sensitivity * (mouseY - (float) height / 2) / height;
			float rotY = sensitivity * (mouseX - (float) width / 2) / height;
		
			glm::vec3 newOrientation = glm::rotate(Orientation, glm::radians(-rotX), glm::normalize(glm::cross(Orientation, Up)));
			newOrientation = glm::rotate(newOrientation, glm::radians(-rotY), Up);
			Orientation = newOrientation;

			glfwSetCursorPos(window, (int) (width / 2), (int) (height / 2));
		}
	} else glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
}

Camera::~Camera() {

}
