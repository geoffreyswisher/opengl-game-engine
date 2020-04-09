#include <SDL2/SDL.h>
#include <stdio.h>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include "display.h"
#include "mesh.h"
#include "shader.h"

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 800;

int main() {
	Display display(SCREEN_WIDTH, SCREEN_HEIGHT);

	Shader shader("../shaders/basicShader");

	Vertex vertices[] = {
		Vertex{glm::vec3{-0.5, -0.5, 0}},
		Vertex{glm::vec3{0, 0.5, 0}},
		Vertex{glm::vec3{0.5, -0.5, 0}},
		Vertex{glm::vec3{1, 0, 0}},
		Vertex{glm::vec3{0, 0.5, 0}},
		Vertex{glm::vec3{0.5, -1, 0}}
	};

	Mesh mesh(vertices, sizeof(vertices)/sizeof(vertices[0]));

	while (!display.IsClosed()) {

		display.ClearScreen(0.5f, 0.2f, 0.4f, 1.0f);

		mesh.Draw();

		shader.Bind();

		display.Update();
	}

	return 0;
}
