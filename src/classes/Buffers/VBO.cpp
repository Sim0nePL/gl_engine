#include "VBO.h"

VBO::VBO() {
	glGenBuffers(1, &id);
}

void VBO::Bind() {
	std::cout << "DEBUG: VBO " << id << " -> " << "Bind" << std::endl;
	glBindBuffer(GL_ARRAY_BUFFER, id);
}

void VBO::Unbind() {
	std::cout << "DEBUG: VBO " << id << " -> " << "Unbind" << std::endl;
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VBO::Delete() {
	std::cout << "DEBUG: VBO " << id << " -> " << "Delete" << std::endl;
	glDeleteBuffers(1, &id);
}

GLuint VBO::GetId() {
	return id;
}

VBO::~VBO() {
}
