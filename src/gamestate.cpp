#include "gamestate.hpp"

//////////////
// Includes //
#include "entities/player.hpp"
#include "rectangle.hpp"

//////////
// Code //

// Constructing a default game state.
GameState::GameState() :
        position(0, 0, 100, 100) {
    player = new Player(0, 0);
}
