#include "component.hpp"

//////////////
// Includes //
#include "../gamestate.hpp"

//////////
// Code //

// Implementing a default constructor for a component.
Component::Component() { }

// Updating the global game state somehow.
Component Component::update(const GameState& gs) { return *this; }
