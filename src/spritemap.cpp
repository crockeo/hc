#include "spritemap.hpp"

//////////////
// Includes //
#include <SDL_image.h>
#include <string>
#include <SDL.h>

#include "hcexception.hpp"
#include "sprite.hpp"
#include "window.hpp"

//////////
// Code //

// Converting 2D coordinates to 1D coordinates.
int SpriteMap::convert(int x, int y) const {
    return y * this->width + x;
}

// Loading a SpriteMap from a file.
SpriteMap::SpriteMap(Window& w, std::string path, int cols, int rows, int width, int height) throw(HCException) {
    SDL_Surface* surf = IMG_Load(path.c_str());
    if (surf == nullptr)
        throw HCException("Failed to load sprite sheet.", HC_ASSET_EXCEPTION);

    for (int i = 0; i < cols * rows; i++) {
        SDL_Surface* tile = SDL_CreateRGBSurface(
            0,
            width, height,
            32,
            0, 0, 0, 0
        );

        SDL_Texture* tileTex = SDL_CreateTextureFromSurface(
            w.getRenderer(),
            tile
        );
        SDL_FreeSurface(tile);
        Sprite* s = new Sprite(tileTex);
        this->sprites.push_back(s);
    }

    SDL_FreeSurface(surf);

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
