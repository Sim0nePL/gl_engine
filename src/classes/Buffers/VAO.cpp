#include "VAO.h"

VAO::VAO() {
	glGenVertexArrays(1, &id);
}

void VAO::Bind() {
	std::cout << "DEBUG: VAO " << id << " -> " << "Bind" << std::endl;
	glBindVertexArray(id);
}

void VAO::Unbind() {
	std::cout << "DEBUG: VAO " << id << " -> " << "Unbind" << std::endl;
	glBindVertexArray(0);
}

void VAO::Delete() {
	std::cout << "DEBUG: VAO " << id << " -> " << "Delete" << std::endl;
	glDeleteVertexArrays(1, &id);
}

GLuint VAO::GetId() {
	return id;
}

VAO::~VAO() {
}
