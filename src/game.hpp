#ifndef _GAME_HPP_
#define _GAME_HPP_

//////////////
// Includes //
#include "gamestate.hpp"
#include "assets.hpp"
#include "window.hpp"

//////////
// Code //

namespace game {
    // Updating the game.
    void update(GameState&, float);

    // Rendering the game.
    void render(GameState&, Window&, const Assets&);
}

#endif
