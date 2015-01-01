#include "game.hpp"

//////////////
// Includes //
#include <SDL.h>

#include "gamestate.hpp"
#include "keyboard.hpp"
#include "assets.hpp"
#include "window.hpp"

#include <iostream>

//////////
// Code //

const float minspeed =  10;
const float accel    = 640;

bool  mx = false, my = false;
float dx = 0    , dy = 0;

bool around(float target, float offset, float value) {
    return value < target + offset &&
           value > target - offset;
}

// Updating the game.
void game::update(GameState& g, float dt) {
    for (auto it = g.timers.begin(); it != g.timers.end(); it++)
        std::get<1>(*it).update();

    mx = false;
    my = false;

    if (g.position.x > 650)
        g.position.x = -460;
    if (g.position.x < -460)
        g.position.x = 650;

    if (keyboard::getKeyState(SDL_SCANCODE_D)) {
        dx += accel * dt;
        mx = true;
    }

    if (keyboard::getKeyState(SDL_SCANCODE_A)) {
        dx -= accel * dt;
        mx = true;
    }

    if (keyboard::getKeyState(SDL_SCANCODE_W)) {
        dy -= accel * dt;
        my = true;
    }

    if (keyboard::getKeyState(SDL_SCANCODE_S)) {
        dy += accel * dt;
        my = true;
    }

    if (!mx) {
        if (dx > 0)
            dx -= accel * dt;
        if (dx < 0)
            dx += accel * dt;

        if (around(0, minspeed, dx))
            dx = 0;
    }

    if (!my) {
        if (dy > 0)
            dy -= accel * dt;
        if (dy < 0)
            dy += accel * dt;

        if (around(0, minspeed, dy))
            dy = 0;
    }

    g.position.translate(dx * dt, dy * dt);
}

// Rendering the game.
void game::render(GameState g, Window& w, const Assets& a) {
    Rectangle r(0, 0, 64, 64);
    Rectangle s(0, 0, 16, 16);
    Rectangle r2(80, 0, 64, 64);
    Rectangle r3(0, 80, 64, 64);

    SDL_RenderClear(w.getRenderer());

    a.sprites.at("res/test.png").blit(w, g.position);
    a.sprites.at("res/forest_tiles.png").blit(w, r, s);
    a.spriteSheets.at("res/forest_tiles.png").blit(w, r2, 0, 0);
    a.animations.at("res/forest_tiles.png").blit(w, r3);

    SDL_RenderPresent(w.getRenderer());
}
