#include "Mesh.h"
#include "Buffers.h"

Mesh::Mesh(Vertex* vertices, unsigned long verticesSize, unsigned int* indices, unsigned long indicesSize) {

	vbo.Bind();
	glBufferData(GL_ARRAY_BUFFER, verticesSize, vertices, GL_STATIC_DRAW);
	
	vao.Bind();
	glVertexAttribPointer(0, 3, GL_FLOAT, false, sizeof(Vertex), 0); // Positions
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 4, GL_FLOAT, false, sizeof(Vertex), (void*) offsetof(Vertex, color)); // Color
	glEnableVertexAttribArray(1);

	ebo.Bind();
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indicesSize, indices, GL_STATIC_DRAW);

	ebo.Unbind();
	vao.Unbind();
	vbo.Unbind();
}

void Mesh::Bind() {
	vbo.Bind();
	vao.Bind();
	ebo.Bind();
}

void Mesh::Unbind() {
	vbo.Unbind();
	vao.Unbind();
	ebo.Unbind();
}

void Mesh::Delete() {
	ebo.Unbind();
	ebo.Delete();

	vao.Unbind();
	vao.Delete();

	vbo.Unbind();
	vbo.Delete();
}

Mesh::~Mesh() {
}
