#ifndef _ENTITY_HPP_
#define _ENTITY_HPP_

//////////////
// Includes //
#include "gamestate.hpp"
#include "rectangle.hpp"
#include "camera.hpp"
#include "window.hpp"

//////////
// Code //

// A class to represent an entity.
template <class T>
class Entity {
protected:
    Rectangle position;

public:
    // Constructing an entity at a given position.
    Entity(Rectangle);

    // Constructing a default entity.
    Entity();

    // Updating this entity and returning a new one.
    virtual void update(const GameState&, float);
    
    // Rendering this entity.
    virtual void render(const Window&, const Camera&);

    // Getting a reference to the rectangle.
    Rectangle getPosition() const;

    // Accessing different information about the Entity.
    float getX()      const;
    float getY()      const;
    float getWidth()  const;
    float getHeight() const;
};

#include "entity.tpp"

#endif
