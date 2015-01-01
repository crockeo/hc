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

// The (unfortunately global) state of the game.
bool quit = false;

// The loop to perform updates.
void updateLoop(GameState& gs) {
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
void renderLoop(const GameState& gs, Window& w, const Assets& a) {
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
    loadAssets(w, a);

    // Initializing the game state.
    GameState gs;
    for (auto it = a.animations.begin(); it != a.animations.end(); it++) {
        std::get<1>(*it).getTimer().start();
        gs.timers.insert(std::pair<std::string, Timer&>(std::get<0>(*it), std::get<1>(*it).getTimer()));
    }

    // Setting the background render color.
    SDL_SetRenderDrawColor(w.getRenderer(), 255, 0, 255, 255);

    // Spinning up the update thread.
    std::thread updateThread(updateLoop, std::ref(gs));

    // Performing the rendering.
    renderLoop(gs, w, a);

    // Waiting for the update thread to finish.
    updateThread.join();

    return 0;
}
