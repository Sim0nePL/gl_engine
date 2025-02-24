#pragma once

#include <iostream>

#include "glad/gl.h"

class EBO {
public:
	EBO();
	~EBO();

	void Bind();
	void Unbind();
	void Delete();

	GLuint GetId();

private:
	GLuint id;
	
};
