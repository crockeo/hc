#include "entity.hpp"

//////////
// Code //

// Creating an entity with a set of components and an ID.
Entity::Entity(std::unordered_map<std::type_index, Component> components, int id) {
    this->components = components;
    this->id = id;
}

// Creating an entity with a given ID.
Entity::Entity(int id) : components() {
    this->id = id;
}

// Constructing a new entity 
Entity Entity::updateComponents(const GameState& gs) {
    std::unordered_map<std::type_index, Component> newComponents;
    for (auto it = this->components.begin(); it != this->components.end(); it++)
        newComponents[std::get<0>(*it)] = std::get<1>(*it).update(gs);

    return Entity(newComponents, this->id);
}

// Pushing a component to the Entity.
void Entity::addComponent(Component c) {
    this->components[std::type_index(typeid(c))] = c;
}

// Getting a copy of a component.
Component Entity::getComponent(std::type_index t) const {
    return this->components.at(t);
}

// Getting the id.
int Entity::getID() const { return this->id; }
