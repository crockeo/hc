#include "entity.hpp"

//////////////
// Includes //
#include "gamestate.hpp"
#include "rectangle.hpp"
#include "assets.hpp"
#include "camera.hpp"
#include "window.hpp"

//////////
// Code //

// Constructing an entity at a given position.
Entity::Entity(Rectangle position) : position(position) { }

// Constructing a default entity.
Entity::Entity() : position(0, 0, 0, 0) { }

// Updating this entity and returning a new one.
void Entity::update(const GameState& gs, float dt) { }

// Rendering this entity.
void Entity::render(Window& w, const Camera& cam, const Assets& assets) { }

// Getting a reference to the rectangle.
Rectangle Entity::getPosition() const { return this->position; }

// Accessing different information about the Entity.
float Entity::getX()      const { return this->position.x; }

float Entity::getY()      const { return this->position.y; }

float Entity::getWidth()  const { return this->position.w; }

float Entity::getHeight() const { return this->position.h; }
