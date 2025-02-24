#version 330 core

layout(location = 0) in vec3 vs_position;
layout(location = 1) in vec4 vs_color;

uniform mat4 Matrix;

out vec4 fs_color;

void main() {
	gl_Position = Matrix * vec4(vs_position, 1.0);
	fs_color = vs_color;
}
