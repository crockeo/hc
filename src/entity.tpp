#include "entity.hpp"

//////////////
// Includes //
#include "gamestate.hpp"
#include "rectangle.hpp"
#include "camera.hpp"
#include "window.hpp"

//////////
// Code //

// Constructing an entity at a given position.
template <class T>
Entity<T>::Entity(Rectangle position) { this->position = position; }

// Constructing a default entity.
template <class T>
Entity<T>::Entity() { this->position = Rectangle(0, 0, 0, 0); }

// Updating this entity and returning a new one.
template <class T>
void Entity<T>::update(const GameState& gs, float dt) { }

// Rendering this entity.
template <class T>
void Entity<T>::render(const Window& w, const Camera& cam) { }

// Getting a reference to the rectangle.
template <class T>
Rectangle Entity<T>::getPosition() const { return this->position; }

// Accessing different information about the Entity.
template <class T>
float Entity<T>::getX()      const { return this->position.x; }

template <class T>
float Entity<T>::getY()      const { return this->position.y; }

template <class T>
float Entity<T>::getWidth()  const { return this->position.w; }

template <class T>
float Entity<T>::getHeight() const { return this->position.h; }
