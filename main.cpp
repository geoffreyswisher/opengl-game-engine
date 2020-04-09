#include <SDL2/SDL.h>
#include <stdio.h>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include "headers/display.h"
#include "headers/mesh.h"
#include "headers/shader.h"
#include "headers/textureLoader.h"

const int SCREEN_WIDTH = 600;
const int SCREEN_HEIGHT = 600;

int main() {
	Display display(SCREEN_WIDTH, SCREEN_HEIGHT);

	Shader shader("../shaders/basicShader.vert", "../shaders/basicShader.frag");

	TextureLoader textureLoader("../textures/container.jpg");

	Vertex vertices[] = {
		Vertex{glm::vec3{-1, -1, 0}, glm::vec3{1.0, 0.0, 0.0}, glm::vec2{-0.5, -0.5}},
		Vertex{glm::vec3{-1, 1, 0}, glm::vec3{0.0, 1.0, 0.0}, glm::vec2{-0.5, 0.5}},
		Vertex{glm::vec3{1, -1, 0}, glm::vec3{0.0, 0.0, 1.0}, glm::vec2{0.5, -0.5}},
		Vertex{glm::vec3{-1, 1, 0}, glm::vec3{1.0, 0.0, 0.0}, glm::vec2{-0.5, 0.5}},
		Vertex{glm::vec3{1, 1, 0}, glm::vec3{0.0, 1.0, 0.0}, glm::vec2{0.5, 0.5}},
		Vertex{glm::vec3{1, -1, 0}, glm::vec3{0.0, 0.0, 1.0}, glm::vec2{0.5, -0.5}}
	};

	Mesh mesh(vertices, sizeof(vertices)/sizeof(vertices[0]));

	while (!display.IsClosed()) {

		display.ClearScreen(0.5f, 0.5f, 0.5f, 1.0f);

		mesh.Draw();

		shader.Bind();

		display.Update();
	}

	return 0;
}
