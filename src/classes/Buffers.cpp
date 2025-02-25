#include "Buffers.h"

// -------------------
//  VBO
VBO::VBO() {
	glGenBuffers(1, &id);
}

void VBO::Bind() {
	//std::cout << "DEBUG: VBO " << id << " -> " << "Bind" << std::endl;
	glBindBuffer(GL_ARRAY_BUFFER, id);
}

void VBO::Unbind() {
	//std::cout << "DEBUG: VBO " << id << " -> " << "Unbind" << std::endl;
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VBO::Delete() {
	//std::cout << "DEBUG: VBO " << id << " -> " << "Delete" << std::endl;
	glDeleteBuffers(1, &id);
}

GLuint VBO::GetId() {
	return id;
}

VBO::~VBO() {
}

// -------------------
//  VAO
VAO::VAO() {
	glGenVertexArrays(1, &id);
}

void VAO::Bind() {
	//std::cout << "DEBUG: VAO " << id << " -> " << "Bind" << std::endl;
	glBindVertexArray(id);
}

void VAO::Unbind() {
	//std::cout << "DEBUG: VAO " << id << " -> " << "Unbind" << std::endl;
	glBindVertexArray(0);
}

void VAO::Delete() {
	//std::cout << "DEBUG: VAO " << id << " -> " << "Delete" << std::endl;
	glDeleteVertexArrays(1, &id);
}

GLuint VAO::GetId() {
	return id;
}

VAO::~VAO() {
}

// -------------------
//  EBO
EBO::EBO() {
	glGenBuffers(1, &id);
	//std::cout << "DEBUG: EBO " << id << " -> " << "Created" << std::endl;
}

void EBO::Bind() {
	//std::cout << "DEBUG: EBO " << id << " -> " << "Bind" << std::endl;
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
}

void EBO::Unbind() {
	//std::cout << "DEBUG: EBO " << id << " -> " << "Unbind" << std::endl;
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void EBO::Delete() {
	//std::cout << "DEBUG: EBO " << id << " -> " << "Delete" << std::endl;
	glDeleteBuffers(1, &id);
}

GLuint EBO::GetId() {
	return id;
}

EBO::~EBO() {
}
