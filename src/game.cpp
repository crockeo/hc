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

const float minspeed =   5;
const float accel    = 640;

Rectangle thingy(2, 400, 20, 80);

bool  mx = false, my = false;
float dx = 0    , dy = 0;
bool  onGround = false;

bool around(float target, float offset, float value) {
    return value < target + offset &&
           value > target - offset;
}

// Updating the game.
void game::update(GameState& g, float dt) {
    for (auto it = g.timers.begin(); it != g.timers.end(); it++)
        std::get<1>(*it).update();

    Collision c = g.position.dirCollides(thingy);
    switch (c) {
    case COLLISION_TOP:
        g.position.y = thingy.bottom();
        dy = 0;
        break;
    case COLLISION_BOTTOM:
        g.position.y = thingy.top() - g.position.h;
        dy = 0;
        break;
    case COLLISION_LEFT:
        g.position.x = thingy.right();
        dx /= -2;
        break;
    case COLLISION_RIGHT:
        g.position.x = thingy.left() - g.position.w;
        dx /= -2;
        break;
    case COLLISION_NONE:
        break;
    }

    mx = false;
    my = false;

    if (g.position.x > 650)
        g.position.x = -g.position.w - 10;
    if (g.position.x < -g.position.w - 10)
        g.position.x = 650;

    if (keyboard::getKeyState(SDL_SCANCODE_D)) {
        if (dx < 0)
            dx += 2 * accel * dt;
        else
            dx += accel * dt;
        mx = true;
    }

    if (keyboard::getKeyState(SDL_SCANCODE_A)) {
        if (dx > 0)
            dx -= 2 * accel * dt;
        else
            dx -= accel * dt;
        mx = true;
    }

    if (onGround && keyboard::getKeyState(SDL_SCANCODE_SPACE)) {
        dy = -400;
    }

    if (!mx) {
        if (dx > 0)
            dx -= accel * dt;
        if (dx < 0)
            dx += accel * dt;

        if (around(0, minspeed, dx))
            dx = 0;
    }

    if (g.position.y + g.position.h < 481) {
        dy += accel * dt;
        onGround = false;
    } else {
        g.position.y = 480 - g.position.h;
        onGround = true;
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
    Rectangle r4(80, 80, 192, 64);

    SDL_RenderClear(w.getRenderer());

    a.spriteSheets.at("res/forest_tiles.png").blit(w, thingy, 1, 0);
    a.sprites.at("res/forest_tiles.png").blit(w, r, s);
    a.spriteSheets.at("res/forest_tiles.png").blit(w, r2, 0, 0);
    a.animations.at("res/forest_tiles.png").blit(w, r3);
    a.sprites.at("res/test.png").blit(w, r4);

    a.animations.at("res/test.png").blit(w, g.position);

    SDL_RenderPresent(w.getRenderer());
}
