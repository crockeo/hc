//////////////
// Includes //
#include <SDL_image.h>
#include <chrono>
#include <thread>
#include <SDL.h>

#include "gamestate.hpp"
#include "rectangle.hpp"
#include "keyboard.hpp"
#include "config.hpp"
#include "sprite.hpp"
#include "window.hpp"
#include "delta.hpp"
#include "game.hpp"

//////////
// Code //

// The assets!
void initAssets(Assets& a) {
    a.addAssetLoad("res/test.png", HC_SPRITE_ASSET);
}

// The (unfortunately global) state of the game.
GameState gs;
bool quit = false;

// The loop to perform updates.
void updateLoop() {
    Delta d;

    while (!quit) {
        keyboard::update();
        float dt = d.since();

        if (dt < 1.f / MAX_UPDATES_PER_SECOND)
            std::this_thread::sleep_for(std::chrono::milliseconds(
                (int)((1.f / MAX_UPDATES_PER_SECOND - dt) * 1000)
            ));

        game::update(gs, dt);
    }
}

// The loop to perform rendering.
void renderLoop(Window& w, const Assets& a) {
    SDL_Event e;
    Delta d;

    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                quit = true;
                break;
            }
        }

        float dt = d.since();

        if (dt < 1.f / MAX_RENDERS_PER_SECOND)
            std::this_thread::sleep_for(std::chrono::milliseconds(
                (int)((1.f / MAX_RENDERS_PER_SECOND - dt) * 1000)
            ));

        game::render(gs, w, a);
    }   
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

    // Spinning up the update thread.
    std::thread updateThread(updateLoop);

    // Performing the rendering.
    renderLoop(w, a);

    // Waiting for the update thread to finish.
    updateThread.join();

    return 0;
}
