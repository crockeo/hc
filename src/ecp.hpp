#ifndef _ECP_HPP_
#define _ECP_HPP_

//////////////
// Includes //
#include <unordered_map>
#include <vector>

#include "ecp/component.hpp"
#include "ecp/entity.hpp"
#include "gamestate.hpp"

//////////
// Code //

// A manager for the entity component system.
class ECP {
private:
    std::unordered_map<int, Entity> entities;
    int index;

public:
    // Creating a new ECP, filled with data.
    ECP(std::unordered_map<int, Entity>, int);

    // Creating a new, empty ECP.
    ECP();

    // Updating the ECP and creating a new copy.
    ECP update(const GameState&);

    // Creating a new entity in the ECP (with a vector of components).
    int newEntity(std::vector<Component>);

    // Creating a new entity in the ECP (with no components).
    int newEntity();

    // Attaching a component to an Entity.
    void attachComponent(int, Component);
};

#endif
