#include "Camera.h"

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

Camera::~Camera() {

}
