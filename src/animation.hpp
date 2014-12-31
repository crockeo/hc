#ifndef _ANIMATION_HPP_
#define _ANIMATION_HPP_

//////////////
// Includes //
#include <vector>
#include <tuple>

#include "spritesheet.hpp"
#include "rectangle.hpp"
#include "window.hpp"

//////////
// Code //

// A class to represent an animation made from a number of frames.
class Animation {
private:
    std::vector<std::tuple<int, int>> order;
    SpriteSheet sheet;
    float frameTime;
    bool repeats;

    // Determining the index of order for a given time.
    int determineIndex(float) const;

public:
    // Constructing an animation from all required info.
    Animation(SpriteSheet, std::vector<std::tuple<int, int>>, float, bool);

    // Constructing an animation with the default ordering (top left to bottom
    // right, by row.)
    Animation(SpriteSheet, float, bool);

    // Rendering a specific frame in an animation.
    void blit(Window&, Rectangle, int) const;

    // Rendering an animation's current frame.
    void blit(Window&, Rectangle) const;
};

#endif
