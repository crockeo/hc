#include "game.hpp"

//////////////
// Includes //
#include <iostream>

#include "gamestate.hpp"
#include "assets.hpp"
#include "window.hpp"

//////////
// Code //

// Updating the game.
void game::update(GameState& g, float dt) {
    if (g.position.x > 650)
        g.position.x = -460;

    g.position.translate(320 * dt, 0);
}

// Rendering the game.
void game::render(GameState g, Window& w, const Assets& a) {
    SDL_RenderClear(w.getRenderer());

    SDL_RenderCopy(w.getRenderer(),
                   a.getSprite("res/test.png").getTexture(),
                   nullptr,
                   &g.position.sdlRect);

    SDL_RenderPresent(w.getRenderer());
}
