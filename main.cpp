#include <SDL2/SDL.h>
#include <stdio.h>
#include <GL/glew.h>
#include "display.h"

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 800;

int main() {
	Display display(SCREEN_WIDTH, SCREEN_HEIGHT);

	while (!display.IsClosed()) {

		display.ClearScreen(0.5f, 0.2f, 0.4f, 1.0f);

		display.Update();
	}

	return 0;
}
