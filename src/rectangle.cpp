#include "rectangle.hpp"

//////////////
// Includes //
#include <math.h>

//////////
// Code //

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
    Rectangle r(*this);
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

// Getting different sides of the rectangle.
float Rectangle::top()    const { return this->y;           }
float Rectangle::bottom() const { return this->y + this->h; }
float Rectangle::left()   const { return this->x;           }
float Rectangle::right()  const { return this->x + this->w; }

// The center of the rectangle on different axes.
float Rectangle::centerX() const { return this->x + this->w / 2; }
float Rectangle::centerY() const { return this->y + this->h / 2; }

// Checking if two rectangles collide.
bool Rectangle::collides(const Rectangle& rect) const {
    Rectangle sw = this->w <= rect.w ? *this : rect;
    Rectangle bw = this->w >  rect.w ? *this : rect;

    Rectangle sh = this->h <= rect.h ? *this : rect;
    Rectangle bh = this->h >  rect.h ? *this : rect;

    bool cLeft   = sw.left()   < bw.right()  && sw.left()   > bw.left();
    bool cRight  = sw.right()  > bw.left()   && sw.right()  < bw.right();

    bool cTop    = sh.top()    < bh.bottom() && sh.top()    > bh.top();
    bool cBottom = sh.bottom() > bh.top()    && sh.bottom() < bh.bottom();

    return (cLeft || cRight) && (cTop || cBottom);
}

// Checking if two rectangles collide and returning the direction of the
// collision.
Collision Rectangle::dirCollides(const Rectangle& rect) const {
    if (!this->collides(rect))
        return COLLISION_NONE;

    float dx = fabs(this->centerX() - rect.centerX());
    float dy = fabs(this->centerY() - rect.centerY());

    if (rect.h > rect.w && dx > dy) {
        if (this->centerX() <= rect.centerX())
            return COLLISION_RIGHT;
        return COLLISION_LEFT;
    } else {
        if (this->centerY() <= rect.centerY())
            return COLLISION_BOTTOM;
        return COLLISION_TOP;
    }
}
