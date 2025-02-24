#pragma once

#include <iostream>

#include "glad/gl.h"

class VAO {
public:
	VAO();
	~VAO();

	void Bind();
	void Unbind();
	void Delete();

	GLuint GetId();

private:
	GLuint id;
	
};
