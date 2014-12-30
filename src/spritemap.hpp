#ifndef _SPRITE_MAP_HPP_
#define _SPRITE_MAP_HPP_

//////////////
// Includes //
#include <string>
#include <vector>

#include "sprite.hpp"

//////////
// Code //

// A set of sprites loaded from a single file.
class SpriteMap {
private:
    std::vector<Sprite*> sprites;
    int width, height;
    bool original;

    // Converting 2D coordinates to 1D coordinates.
    int convert(int, int) const;

public:
    // Loading a SpriteMap from a file.
    SpriteMap(std::string);

    // A copy constructor!
    SpriteMap(const SpriteMap&);

    // Destroying the SpriteMap.
    ~SpriteMap();

    // Getting a sprite at a given (x, y) coordinate.
    Sprite getSprite(int, int) const;
};

#endif
