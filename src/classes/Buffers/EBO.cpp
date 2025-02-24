#include "EBO.h"

EBO::EBO() {
	glGenBuffers(1, &id);
}

void EBO::Bind() {
	std::cout << "DEBUG: EBO " << id << " -> " << "Bind" << std::endl;
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
}

void EBO::Unbind() {
	std::cout << "DEBUG: EBO " << id << " -> " << "Unbind" << std::endl;
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void EBO::Delete() {
	std::cout << "DEBUG: EBO " << id << " -> " << "Delete" << std::endl;
	glDeleteBuffers(1, &id);
}

GLuint EBO::GetId() {
	return id;
}

EBO::~EBO() {
}
