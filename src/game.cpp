#include "game.hpp"

//////////////
// Includes //
#include <SDL.h>

#include "gamestate.hpp"
#include "keyboard.hpp"
#include "assets.hpp"
#include "window.hpp"

//////////
// Code //

// Updating the game.
void game::update(GameState& g, float dt) {
    // Updating all of the timers.
    for (auto it = g.timers.begin(); it != g.timers.end(); it++)
        std::get<1>(*it).update();

    // Updating the player.
    g.player->update(g, dt);

    // Moving the camera to the player.
    g.cam.translate((g.player->getX() - g.cam.x - 320 + 50) * dt * 8,
                    (g.player->getY() - g.cam.y - 240 + 50) * dt * 8);
}

// Rendering the game.
void game::render(GameState g, Window& w, const Assets& a) {
    SDL_RenderClear(w.getRenderer());

    g.tilemap->render(w, g.cam, a);
    g.player->render(w, g.cam, a);
    for (auto it = g.blocks.begin(); it != g.blocks.end(); it++)
        (*it)->render(w, g.cam, a);
    SDL_RenderPresent(w.getRenderer());
}
