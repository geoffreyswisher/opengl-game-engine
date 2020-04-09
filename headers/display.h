#ifndef DISPLAY_H
#define DISPLAY_H

#include <SDL2/SDL.h>

class Display {
    public:
        Display(int width, int height);

        bool IsClosed();
        void Update();
        void ClearScreen(float r, float g, float b, float a);

        virtual ~Display();

    protected:
    private:
        Display(const Display& other) {}
        void operator=(const Display& other) {}

        SDL_Window* window;
        SDL_GLContext glContext;

        bool isClosed;


};

#endif