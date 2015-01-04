#ifndef _RECTANGLE_HPP_
#define _RECTANGLE_HPP_

//////////////
// Includes //
#include <SDL.h>

//////////
// Code //

// Different kinds of collisions that can occur.
enum Collision {
    COLLISION_TOP,
    COLLISION_BOTTOM,
    COLLISION_LEFT,
    COLLISION_RIGHT,
    COLLISION_NONE
};

struct Rectangle {
    SDL_Rect sdlRect;
    float x, y, w, h;

    // Creating a god damn motherfucking rectangle.
    Rectangle(float, float, float, float);

    // Translating a rectangle.
    void translate(float, float);

    // Translating a rectangle by creating a new one.
    Rectangle fTranslate(float, float) const;

    // Updating the SDL rectangle.
    void updateSDLRect();

    // Getting different sides of the rectangle.
    float top()    const;
    float bottom() const;
    float left()   const;
    float right()  const;

    // The center of the rectangle on different axes.
    float centerX() const;
    float centerY() const;

    // Checking if two rectangles collide.
    bool collides(const Rectangle&) const;

    // Checking if two rectangles collide and returning the direction of the
    // collision.
    Collision dirCollides(const Rectangle&) const;
};

#endif
