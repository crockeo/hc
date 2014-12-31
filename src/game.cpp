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

const float accel = 640;
float dx = 0, dy = 0;

// Updating the game.
void game::update(GameState& g, float dt) {
    if (g.position.x > 650)
        g.position.x = -460;
    if (g.position.x < -460)
        g.position.x = 650;

    if (keyboard::getKeyState(SDL_SCANCODE_D))
        dx += accel * dt;
    if (keyboard::getKeyState(SDL_SCANCODE_A))
        dx -= accel * dt;
    if (keyboard::getKeyState(SDL_SCANCODE_W))
        dy -= accel * dt;
    if (keyboard::getKeyState(SDL_SCANCODE_S))
        dy += accel * dt;

    g.position.translate(dx * dt, dy * dt);
}

// Rendering the game.
void game::render(GameState g, Window& w, const Assets& a) {
    Rectangle r(0, 0, 64, 64);

    SDL_RenderClear(w.getRenderer());

    SDL_RenderCopy(w.getRenderer(),
                   a.getSprite("res/test.png").getTexture(),
                   nullptr,
                   &g.position.sdlRect);

    SDL_RenderCopy(w.getRenderer(),
                   a.getSpriteMap("res/forest_tiles.png").getSprite(0, 0).getTexture(),
                   nullptr,
                   &r.sdlRect);

    SDL_RenderPresent(w.getRenderer());
}
