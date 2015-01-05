#include "gamestate.hpp"

//////////////
// Includes //
#include "rectangle.hpp"
#include "player.hpp"

//////////
// Code //

Player tmpPlayer(50, 50);

// Constructing a default game state.
GameState::GameState() :
        player(tmpPlayer),
        position(0, 0, 100, 100) {
}
