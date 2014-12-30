#include "spritemap.hpp"

//////////////
// Includes //
#include <string>

//////////
// Code //

// Converting 2D coordinates to 1D coordinates.
int SpriteMap::convert(int x, int y) const {
    return y * this->width + x;
}

// Loading a SpriteMap from a file.
SpriteMap::SpriteMap(std::string) {
    // TODO: Load a spritemap
    this->original = true;
}

// A copy constructor!
SpriteMap::SpriteMap(const SpriteMap& sm) {
    this->sprites = sm.sprites;
    this->original = false;
}

// Destroying the SpriteMap.
SpriteMap::~SpriteMap() {
    if (this->original) {
        for (auto it = this->sprites.begin(); it != this->sprites.end(); it++) {
            delete *it;
        }
    }
}

// Getting a sprite at a given (x, y) coordinate.
Sprite SpriteMap::getSprite(int x, int y) const {
    return *this->sprites[this->convert(x, y)];
}
