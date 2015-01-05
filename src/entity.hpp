#ifndef _ENTITY_HPP_
#define _ENTITY_HPP_

//////////////
// Includes //
#include "gamestate.hpp"
#include "rectangle.hpp"
#include "assets.hpp"
#include "camera.hpp"
#include "window.hpp"

//////////
// Code //

class GameState;

// A class to represent an entity.
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
    virtual void render(Window&, const Camera&, const Assets&);

    // Getting a reference to the rectangle.
    Rectangle getPosition() const;

    // Accessing different information about the Entity.
    float getX()      const;
    float getY()      const;
    float getWidth()  const;
    float getHeight() const;
};

#endif
