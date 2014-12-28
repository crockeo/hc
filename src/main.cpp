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

// The assets!
void initAssets(Assets& a) {
    a.addAssetLoad("res/test.png", HC_SPRITE_ASSET);
}

// Entry point!
int main() {
    // Opening the window.
    Window w("Hello World!", 640, 480, false);

    // Loading and initializing assets.
    Assets a;
    initAssets(a);
    a.performLoads(w);

    SDL_SetRenderDrawColor(w.getRenderer(), 255, 0, 255, 255);

    // Starting the game loop.
    bool quit = false;
    SDL_Event e;
    float dt = 0;
    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                quit = true;
                break;
            }
        }

        game::update(dt);
        game::render(w, a);
    }

    return 0;
}
