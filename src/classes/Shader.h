#pragma once
#include <glad/gl.h>

#include <iostream>
#include <fstream>
#include <sstream>
#include <cassert>

class Shader {
public:
	Shader(const std::string& vsFile, const std::string& fsFile);
	~Shader();
	
	// Create shader and put id into shaderId
	// Returns compilation status and prints glsl error
	int CreateShader(unsigned int type, const std::string& source, unsigned int& shaderId);

	std::string ReadShader(const std::string& filepath);
	void Bind();
	void Unbind();
	void Delete();
	
	unsigned int GetId();

private:
	unsigned int id = 0;
};
