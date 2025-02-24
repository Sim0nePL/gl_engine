#pragma once

#include "Buffers.h"
#include "Mesh.h"
#include <GL/gl.h>

class Renderer {
public:
	static void Render(Mesh& mesh) {
		mesh.Bind();
		glDrawElements(GL_TRIANGLES, mesh.count, GL_UNSIGNED_INT, 0);
		mesh.Unbind();
	}

private:
		
};
