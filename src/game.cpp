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
    if (g.position.x > 650)
        g.position.x = -460;

    if (keyboard::getKeyState(SDL_SCANCODE_D))
        g.position.translate(320 * dt, 0);
    if (keyboard::getKeyState(SDL_SCANCODE_A))
        g.position.translate(-320 * dt, 0);
    if (keyboard::getKeyState(SDL_SCANCODE_W))
        g.position.translate(0, -320 * dt);
    if (keyboard::getKeyState(SDL_SCANCODE_S))
        g.position.translate(0, 320 * dt);

    //g.position.translate(320 * dt, 0);
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
