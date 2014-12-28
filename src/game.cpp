#include "game.hpp"

//////////////
// Includes //
#include "rectangle.hpp"
#include "assets.hpp"
#include "window.hpp"

//////////
// Code //

// Updating the game.
void game::update(float dt) {

}

// Rendering the game.
void game::render(Window& w, const Assets& a) {
    SDL_RenderClear(w.getRenderer());

    Rectangle r(640 / 2 - 450 / 2, 480 / 2 - 150 / 2, 450, 150);
    SDL_RenderCopy(w.getRenderer(),
                   a.getSprite("res/test.png").getTexture(),
                   nullptr,
                   &r.sdlRect);

    SDL_RenderPresent(w.getRenderer());
}
