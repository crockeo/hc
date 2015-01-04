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
Rectangle base  (-1000, 480, 2000, 10);

bool  mx = false, my = false;
float dx = 0    , dy = 0;
bool  onGround = false;

bool around(float target, float offset, float value) {
    return value < target + offset &&
           value > target - offset;
}

void performCollision(Rectangle& src, const Rectangle& target) {
    switch (src.dirCollides(target)) {
    case COLLISION_TOP:
        if (dy <= 0) {
            src.y = target.bottom();
            dy = 0;
        }

        break;
    case COLLISION_BOTTOM:
        if (dy >= 0) {
            src.y = target.top() - src.h;
            onGround = true;
            dy = 0;
        }

        break;
    case COLLISION_LEFT:
        src.x = target.right();
        dx /= -2;
        break;
    case COLLISION_RIGHT:
        src.x = target.left() - src.w;
        dx /= -2;
        break;
    case COLLISION_NONE:
        break;
    }
}

// Updating the game.
void game::update(GameState& g, float dt) {
    for (auto it = g.timers.begin(); it != g.timers.end(); it++)
        std::get<1>(*it).update();

    performCollision(g.position, thingy);
    performCollision(g.position, base);

    mx = false;
    my = false;

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
        onGround = false;
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

    if (!onGround)
        dy += accel * dt;

    g.position.translate(dx * dt, dy * dt);

    g.cam.translate((g.position.x - g.cam.x - 320 + 50) * dt * 8, (g.position.y - g.cam.y - 240 + 50) * dt * 8);
}

// Rendering the game.
void game::render(GameState g, Window& w, const Assets& a) {
    Rectangle r(0 - g.cam.x, 0 - g.cam.y, 64, 64);
    Rectangle s(0, 0, 16, 16);
    Rectangle r2(80 - g.cam.x, 0 - g.cam.y, 64, 64);
    Rectangle r3(0 - g.cam.x, 80 - g.cam.y, 64, 64);
    Rectangle r4(80 - g.cam.x, 80 - g.cam.y, 192, 64);

    Rectangle rt(thingy);
    rt.translate(-g.cam.x, -g.cam.y);

    Rectangle rb(base);
    rb.translate(-g.cam.x, -g.cam.y);

    g.position.translate(-g.cam.x, -g.cam.y);

    SDL_RenderClear(w.getRenderer());

    a.spriteSheets.at("res/forest_tiles.png").blit(w, rb, 0, 0);
    a.spriteSheets.at("res/forest_tiles.png").blit(w, rt, 1, 0);
    a.sprites.at("res/forest_tiles.png").blit(w, r, s);
    a.spriteSheets.at("res/forest_tiles.png").blit(w, r2, 0, 0);
    a.animations.at("res/forest_tiles.png").blit(w, r3);
    a.sprites.at("res/test.png").blit(w, r4);

    a.animations.at("res/test.png").blit(w, g.position);

    SDL_RenderPresent(w.getRenderer());
}
