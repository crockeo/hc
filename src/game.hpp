#ifndef _GAME_HPP_
#define _GAME_HPP_

//////////////
// Includes //
#include "assets.hpp"
#include "window.hpp"

//////////
// Code //

namespace game {
    // Updating the game.
    void update(float);

    // Rendering the game.
    void render(Window&, const Assets&);
}

#endif
