#ifndef _GAME_STATE_HPP_
#define _GAME_STATE_HPP_

//////////////
// Includes //
#include <unordered_map>
#include <string>

#include "rectangle.hpp"
#include "timer.hpp"

//////////
// Code //

// A class to house the current state of the game.
struct GameState {
    // Constructing a default game state.
    GameState();

    std::unordered_map<std::string, Timer&> timers;

    Rectangle position;
};

#endif
