#ifndef _RECTANGLE_HPP_
#define _RECTANGLE_HPP_

//////////////
// Includes //
#include <SDL.h>

//////////
// Code //

struct Rectangle {
    SDL_Rect sdlRect;
    float x, y, w, h;

    // Creating a god damn motherfucking rectangle.
    Rectangle(float, float, float, float);

    // Checking if two rectangles collide.
    bool collides(const Rectangle&) const;
};

#endif
