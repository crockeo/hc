#include "game.hpp"

//////////////
// Includes //
#include <iostream>

#include "rectangle.hpp"
#include "assets.hpp"
#include "window.hpp"

//////////
// Code //

Rectangle r(
    640 / 2 - 450 / 2, 480 / 2 - 150 / 2,
    450, 150
);

// Updating the game.
void game::update(float dt) {
    if (r.x > 650)
        r.x = -460;

    r.translate(0.5, 0.0);
}

// Rendering the game.
void game::render(Window& w, const Assets& a) {
    SDL_RenderClear(w.getRenderer());

    SDL_RenderCopy(w.getRenderer(),
                   a.getSprite("res/test.png").getTexture(),
                   nullptr,
                   &r.sdlRect);

    SDL_RenderPresent(w.getRenderer());
}
