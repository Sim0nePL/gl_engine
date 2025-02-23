#include "Shader.h"

Shader::Shader(const std::string& vsFile, const std::string& fsFile) {
	const std::string& vertexShaderSource = ReadShader(vsFile);
	unsigned int vertexShader;
	if (CreateShader(GL_VERTEX_SHADER, vertexShaderSource, vertexShader) == GL_FALSE) {
		glDeleteShader(vertexShader);
		vertexShader = 0;
	}

	const std::string& fragmentShaderSource = ReadShader(fsFile);
	unsigned int fragmentShader;
	if (CreateShader(GL_FRAGMENT_SHADER, fragmentShaderSource, fragmentShader) == GL_FALSE) {
		glDeleteShader(fragmentShader);
		fragmentShader = 0;
	}

	if (vertexShader == 0 || fragmentShader == 0)
		return;

	id = glCreateProgram();
	glAttachShader(id, vertexShader);
	glAttachShader(id, fragmentShader);
	glLinkProgram(id);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

int Shader::CreateShader(unsigned int type, const std::string& source, unsigned int& shaderId) {
	unsigned int id = glCreateShader(type);
	const char* src = source.c_str();
	glShaderSource(id, 1, &src, nullptr);
	glCompileShader(id);

	int result;
	glGetShaderiv(id, GL_COMPILE_STATUS, &result);
	if (result == GL_FALSE) {
		int length;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
		char message[length];
		glGetShaderInfoLog(id, length, &length, message);
		std::cout << "FAILED TO COMPILE " << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << " shader!" << std::endl;
		std::cout << message << std::endl;
	}
	
	shaderId = id;

	return result;
}

std::string Shader::ReadShader(const std::string& filepath) {
	std::ifstream stream(filepath);
	assert(stream.is_open());

	std::string line;
	std::stringstream ss;
	while (getline(stream, line)) {
		ss << line << '\n';
	}

	return ss.str();

}

void Shader::Bind() {
	glUseProgram(id);
}

void Shader::Unbind() {
	glUseProgram(0);
}

void Shader::Delete() {
	glDeleteProgram(id);
}

Shader::~Shader() {
}

unsigned int Shader::GetId() {
	return id;
}
