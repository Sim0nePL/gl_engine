#include <iostream>

#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include "imgui.h"
#include "backends/imgui_impl_opengl3.h"
#include "backends/imgui_impl_glfw.h"

#include "classes/Camera.h"
#include "classes/Renderer.h"
#include "classes/Shader.h"
#include "classes/Vertex.h"
#include "classes/Mesh.h"

// -------------------------------------------------------------------
//
//		TODO: 
//			- Tweak Mesh Class to use arrays instead of shitload
//					useless vars [ vertices, verticesSize, count ]. wtf
//																						it's 4 am...
//			- Add Translation Matrix to mesh and position property
//			- Abstract Window Class so delete 
//					functions could be in deconstructors
//					after that glfwTerminate() will be called.
//			- Some prefabs class based on Mesh.
//			- FPS counter. -> imgui says hello
//			- Some textures						|
//																|
//					Future plans:				  ⌄
//			-	Try to add GUI with power of creation things.
//			- Hot Reloading
//			- Input Handling system
//			- DSA would be cool
//
// ------------------------------------------------------------

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
	Vertex vertices[] {
		//	Position												Color
		{ -0.5, -0.5,  0.0f, 				1.0f, 0.0f, 0.0f, 1.0f, }, // Bottom Left
		{  0.5, -0.5,  0.0f, 				0.0f, 1.0f, 0.0f, 1.0f, }, // Bottom Right
		{  0.5,  0.5,  0.0f, 				0.0f, 0.0f, 1.0f, 1.0f, }, // Top Right
		{ -0.5,  0.5,  0.0f, 				1.0f, 1.0f, 1.0f, 1.0f, }, // Top Left
	};

	unsigned int indices[] {
		0, 1, 2,
		2, 3, 0
	};

	// Buffers
	Mesh plane(vertices, sizeof(vertices), indices, sizeof(indices), sizeof(indices) / sizeof(unsigned int));

	// Shader
	Shader shader("./src/shaders/shader.vert", "./src/shaders/shader.frag");
	shader.Bind();

	// Camera
	Camera camera(screenWidth, screenHeight, { 0.0f, 0.0f, 2.0f } );

	bool isPressed = false;

	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	ImGui::StyleColorsDark();
	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init("#version 330");

	bool bDraw = true;

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		// Shader Hotreload
		if(glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS) {
			if(!isPressed) {
				std::cout << "Pressed" << std::endl;
				shader.Unbind();
				shader.Delete();
				shader = Shader("./src/shaders/shader.vert", "./src/shaders/shader.frag");
				shader.Bind();

				isPressed = true;
			}
		} else isPressed = false;


		camera.Inputs(window);

		// Render here
		glClear(GL_COLOR_BUFFER_BIT);

		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

		camera.Matrix(shader, "Matrix");
	
		if(bDraw)
			Renderer::Render(plane);

		ImGui::Begin("Jebac ci starego");
		ImGui::Text("i starom");
		ImGui::Checkbox("Draw Triangle", &bDraw);
		ImGui::End();

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		// Swap front and back buffers
		glfwSwapBuffers(window);

		// Poll for and process events
		glfwPollEvents();
	}

	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();

	plane.Delete();

	glfwTerminate();

	return 0;
}
