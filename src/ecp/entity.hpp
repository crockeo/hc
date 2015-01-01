#ifndef _ENTITY_HPP_
#define _ENTITY_HPP_

//////////////
// Includes //
#include <unordered_map>
#include <typeindex>

#include "../hcexception.hpp"
#include "../gamestate.hpp"
#include "component.hpp"

//////////
// Code //

// An entity that contains a set of components.
class Entity {
private:
    std::unordered_map<std::type_index, Component> components;
    int id;

public:
    // Creating an entity with a set of components and an ID.
    Entity(std::unordered_map<std::type_index, Component>, int);

    // Creating an entity with a given ID.
    Entity(int);

    // Constructing a new entity 
    Entity update(const GameState&) throw(HCException);
    
    // Pushing a component to the Entity.
    void addComponent(Component);

    // Getting a copy of a component.
    Component getComponent(std::type_index) const;

    // Getting the id.
    int getID() const;
};

#endif
