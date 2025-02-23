#include <iostream>

#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include "classes/Camera.h"
#include "classes/Shader.h"

int main (int argc, char *argv[]) {
	std::cout << "OpenGL Template !float" << std::endl;

/* Initialize the library */
	if (!glfwInit()) {
			return -1;
	}

	int screenWidth = 1280, screenHeight = 720;

	GLFWwindow* window = glfwCreateWindow(screenWidth, screenHeight, "TEMPLATE !float", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	int version = gladLoadGL(glfwGetProcAddress);
	if (version == 0) {
		printf("Failed to initialize OpenGL context\n");
		return -1;
	}

	// Successfully loaded OpenGL
	printf("Loaded OpenGL %d.%d\n", GLAD_VERSION_MAJOR(version), GLAD_VERSION_MINOR(version));

	// Game Initialization
	//  Object
	float vertices[] {
		-0.5f, -0.5f,  0.0f,
		 0.5f, -0.5f,  0.0f,
		 0.0f,  0.5f,  0.0f,
	};

	unsigned int indices[] {
		0, 1, 2,
	};

	// Buffers
	unsigned int VAO;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	unsigned int VBO, EBO;
	// - VBO
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, false, 3 * sizeof(float), 0); // VAO attributes pointer
	glEnableVertexAttribArray(0);

	// - EBO
	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// Shader
	Shader shader("./src/shaders/shader.vert", "./src/shaders/shader.frag");
	shader.Bind();

	// Camera
	Camera camera(screenWidth, screenWidth, { 0.0f, 0.0f, 2.0f} );

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{	
		// Render here
		glClear(GL_COLOR_BUFFER_BIT);
		camera.Matrix(shader, "Matrix");
	
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);

		// Swap front and back buffers
		glfwSwapBuffers(window);

		// Poll for and process events
		glfwPollEvents();
	}

	shader.Unbind();
	shader.Delete();

	glfwTerminate();

	return 0;
}
