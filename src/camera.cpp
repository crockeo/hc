#include "camera.hpp"

//////////
// Code //

// Creating a new camera at a given position.
Camera::Camera(float x, float y) {
    this->x = x;
    this->y = y;
}

// Creating a new camera at (0, 0)
Camera::Camera() {
    this->x = 0;
    this->y = 0;
}

// Translating the camera.
void Camera::translate(float dx, float dy) {
    this->x += dx;
    this->y += dy;
}

// Purely translating the camera.
Camera Camera::fTranslate(float dx, float dy) const {
    Camera cam(*this);
    cam.translate(dx, dy);
    return cam;
}

// Moving the camera to a position.
void Camera::moveTo(float x, float y) {
    this->x = x;
    this->y = y;
}

// Purely moving the camera to a position.
Camera Camera::fMoveTo(float x, float y) const {
    Camera cam(*this);
    cam.moveTo(x, y);
    return cam;
}
