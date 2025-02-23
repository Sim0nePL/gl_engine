#include <iostream>
#include <glad/gl.h>
#include <GLFW/glfw3.h>

int main (int argc, char *argv[]) {
	std::cout << "OpenGL Template !float" << std::endl;
	
/* Initialize the library */
	if (!glfwInit()) {
			return -1;
	}

	GLFWwindow* window = glfwCreateWindow(1280, 720, "TEMPLATE !float", NULL, NULL);
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

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();

	return 0;
}
