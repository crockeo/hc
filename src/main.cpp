//////////////
// Includes //
#include <SDL_image.h>
#include <SDL.h>

#include "rectangle.hpp"
#include "sprite.hpp"
#include "window.hpp"
#include "game.hpp"

//////////
// Code //

// Entry point!
int main() {
    Window w("Hello World!", 640, 480, false);

    Sprite s(w.getRenderer(), "res/test.png");

    SDL_SetRenderDrawColor(w.getRenderer(), 255, 0, 255, 255);
    SDL_RenderClear(w.getRenderer());

    Rectangle r(640 / 2 - 450 / 2, 480 / 2 - 150 / 2, 450, 150);
    SDL_RenderCopy(w.getRenderer(),
                   s.getTexture(),
                   nullptr,
                   &r.sdlRect);

    SDL_RenderPresent(w.getRenderer());

    SDL_Event e;
    while (SDL_WaitEvent(&e)) {
        if (e.type == SDL_QUIT)
            break;
    }

    return 0;
}
