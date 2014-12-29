#ifndef _GAME_STATE_HPP_
#define _GAME_STATE_HPP_

//////////////
// Includes //
#include "rectangle.hpp"

//////////
// Code //

// A class to house the current state of the game.
struct GameState {
    // Constructing a default game state.
    GameState();

    Rectangle position;
};

#endif
