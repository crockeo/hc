#ifndef _CAMERA_HPP_
#define _CAMERA_HPP_

//////////
// Code //

// A struct to represent a camera.
struct Camera {
    float x, y;

    // Creating a new camera at a given position.
    Camera(float, float);

    // Creating a new camera at (0, 0)
    Camera();

    // Translating the camera.
    void translate(float, float);

    // Purely translating the camera.
    Camera fTranslate(float, float) const;

    // Moving the camera to a position.
    void moveTo(float, float);

    // Purely moving the camera to a position.
    Camera fMoveTo(float, float) const;
};

#endif
