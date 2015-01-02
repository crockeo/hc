#include "ecp.hpp"

//////////
// Code //

// Creating a new ECP, filled with data.
ECP::ECP(std::vector<Entity> entities, int index) {
    this->entities = entities;
    this->index = index;
}

// Creating a new, empty ECP.
ECP::ECP() {
    this->entities = std::vector<Entity>();
    this->index = 0;
}

// Updating the ECP and creating a new copy.
ECP ECP::update(const GameState& gs, float dt) {
    ECP copy(*this);
    for (int i = 0; i < copy.entities.size(); i++)
        copy.entities[i] = copy.entities[i].update(gs, dt);
    return copy;
}

// Creating a new entity in the ECP (with a vector of components).
int ECP::newEntity(std::vector<Component> components) {
    int index = this->entities.size();
    this->entities.push_back(Entity(index));

    for (auto it = components.begin(); it != components.end(); it++)
        this->attachComponent(index, *it);

    return index;
}

// Creating a new entity in the ECP (with no components).
int ECP::newEntity() { return this->newEntity(std::vector<Component>()); }

// Attaching a component to an Entity.
void ECP::attachComponent(int index, Component c) {
    this->entities[index].addComponent(c);
}
