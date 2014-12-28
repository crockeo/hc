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

    // Translating a rectangle.
    void translate(float, float);

    // Translating a rectangle by creating a new one.
    Rectangle fTranslate(float, float) const;

    // Updating the SDL rectangle.
    void updateSDLRect();

    // Checking if two rectangles collide.
    bool collides(const Rectangle&) const;
};

#endif
