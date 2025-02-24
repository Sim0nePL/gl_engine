#pragma once

#include <iostream>

#include "glad/gl.h"

class VBO {
public:
	VBO();
	~VBO();

	void Bind();
	void Unbind();
	void Delete();

	GLuint GetId();

private:
	GLuint id;
	
};
