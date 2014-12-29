//////////////
// Includes //
#include <SDL_image.h>
#include <chrono>
#include <SDL.h>

// GET RID OF THIS.
#include <iostream>

#include "rectangle.hpp"
#include "sprite.hpp"
#include "window.hpp"
#include "game.hpp"

//////////
// Code //

int getTimeMillis() {
    auto now = std::chrono::system_clock::now();
    return std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()).count();
}

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

    int curr = getTimeMillis(), last = getTimeMillis();
    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                quit = true;
                break;
            }
        }

        curr = getTimeMillis();
        float dt = (curr - last) / 1000.f;

        game::update(dt);
        game::render(w, a);

        last = curr;
    }

    return 0;
}
