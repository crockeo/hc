#include "rectangle.hpp"

// Creating a god damn motherfucking rectangle.
Rectangle::Rectangle(float x, float y, float w, float h) {
    this->sdlRect.x = (int)x;
    this->sdlRect.y = (int)y;
    this->sdlRect.w = (int)w;
    this->sdlRect.h = (int)h;

    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
}

// Checking if two rectangles collide.
bool Rectangle::collides(const Rectangle& rect) const {
    return false;
}