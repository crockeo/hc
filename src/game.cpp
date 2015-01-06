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
    Rectangle r(0 - g.cam.x, 0 - g.cam.y, 64, 64);
    Rectangle s(0, 0, 16, 16);
    Rectangle r2(80 - g.cam.x, 0 - g.cam.y, 64, 64);
    Rectangle r3(0 - g.cam.x, 80 - g.cam.y, 64, 64);
    Rectangle r4(80 - g.cam.x, 80 - g.cam.y, 192, 64);

    g.position.translate(-g.cam.x, -g.cam.y);

    SDL_RenderClear(w.getRenderer());

    g.player->render(w, g.cam, a);
    for (auto it = g.blocks.begin(); it != g.blocks.end(); it++)
        (*it)->render(w, g.cam, a);

    a.sprites.at("res/forest_tiles.png").blit(w, r, s);
    a.spriteSheets.at("res/forest_tiles.png").blit(w, r2, 0, 0);
    a.animations.at("res/forest_tiles.png").blit(w, r3);
    a.sprites.at("res/test.png").blit(w, r4);

    a.animations.at("res/test.png").blit(w, g.position);

    SDL_RenderPresent(w.getRenderer());
}
