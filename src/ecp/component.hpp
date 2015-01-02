#ifndef _COMPONENT_HPP_
#define _COMPONENT_HPP_

//////////////
// Includes //
#include "../gamestate.hpp"

//////////
// Code //

// A class to represent a single component
class Component {
public:
    // Implementing a default constructor for a component.
    Component();

    // Updating the global game state somehow.
    virtual Component update(const GameState&, float);
};

#endif
