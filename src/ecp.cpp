#include "ecp.hpp"

//////////
// Code //

// Creating a new ECP, filled with data.
ECP::ECP(std::unordered_map<int, Entity>, int) { }

// Creating a new, empty ECP.
ECP::ECP() { }

// Updating the ECP and creating a new copy.
ECP ECP::update(const GameState&) { return *this; }

// Creating a new entity in the ECP (with a vector of components).
int ECP::newEntity(std::vector<Component>) { return 0; }

// Creating a new entity in the ECP (with no components).
int ECP::newEntity() { return 0; }

// Attaching a component to an Entity.
void ECP::attachComponent(int, Component) { }
