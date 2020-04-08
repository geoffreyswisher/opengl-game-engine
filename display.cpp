#include "display.h"
#include <GL/glew.h>
#include <iostream>

// Constructor
Display::Display(int width, int height) {

    //initialize SDL
    SDL_Init(SDL_INIT_EVERYTHING);

    // Double window so the one being displayed is not currently being drawn on
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    window = SDL_CreateWindow("Window", 500, 500, width, height, SDL_WINDOW_OPENGL);

    // Context allows for GPU to have partial control over the window
    // OS no longer has full control over the window
    glContext = SDL_GL_CreateContext(window);

    // Initialize GLEW
    GLenum res = glewInit();
    if (res != GLEW_OK) {
        std::cerr << "Glew failed to initialize!" << std::endl;
    }

    isClosed = false;
}

// Deconstructor
Display::~Display() {
    SDL_GL_DeleteContext(glContext);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

bool Display::IsClosed() {
    return isClosed;
}

void Display::Update() {
    SDL_GL_SwapWindow(window);

    // Check for exit
    SDL_Event e;

    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_QUIT) {
            isClosed = true;
        }
    }
}

// Clears the screen with a color
void Display::ClearScreen(float r, float g, float b, float a) {
    glClearColor(r, g, b, a);

    // sets the bitplane area of the window to the value selected by glClearColor
	glClear(GL_COLOR_BUFFER_BIT);
}