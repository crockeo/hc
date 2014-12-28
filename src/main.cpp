//////////////
// Includes //
#include <SDL_image.h>
#include <SDL.h>

#include "window.hpp"

//////////
// Code //

// Entry point!
int main() {
    Window* const w = new Window("Hello World!", 640, 480, false);

    SDL_Event e;
    while (SDL_WaitEvent(&e)) {
        if (e.type == SDL_QUIT)
            break;
    }

    delete w;
    return 0;
}
