#include "rectangle.hpp"

// Creating a god damn motherfucking rectangle.
Rectangle::Rectangle(float x, float y, float w, float h) {
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;

    this->updateSDLRect();
}

// Translating a rectangle.
void Rectangle::translate(float dx, float dy) {
    this->x += dx;
    this->y += dy;

    this->updateSDLRect();
}

// Translating a rectangle by creating a new one.
Rectangle Rectangle::fTranslate(float dx, float dy) const {
    Rectangle r = *this;
    r.translate(dx, dy);
    return r;
}

// Updating the SDL rectangle.
void Rectangle::updateSDLRect() {
    this->sdlRect.x = (int)x;
    this->sdlRect.y = (int)y;
    this->sdlRect.w = (int)w;
    this->sdlRect.h = (int)h;
}

// Checking if two rectangles collide.
bool Rectangle::collides(const Rectangle& rect) const {
    return false;
}
