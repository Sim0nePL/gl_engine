#pragma once

#include "Vertex.h"
#include "Buffers.h"
#include "glad/gl.h"

class Mesh {
public:
	Mesh(Vertex* vertices, unsigned long verticesSize, unsigned int* indices, unsigned long indicesSize, unsigned int count);
	~Mesh();
	void Bind();
	void Unbind();
	void Delete();
	
	VBO vbo;
	VAO vao;
	EBO ebo;

	unsigned int count;
};

