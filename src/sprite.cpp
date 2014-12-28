#include "sprite.hpp"

//////////////
// Includes //
#include <SDL_image.h>
#include <SDL.h>

//////////
// Code //

// Making a Sprite from an existing SDL_Texture.
Sprite::Sprite(SDL_Texture* tex) throw(HCException) {
    if (tex == nullptr)
        throw HCException("Cannot create a Sprite from a non-existent texture.\n", HC_ASSET_EXCEPTION);
    this->tex = tex;
}

// Making a Sprite from an SDL_Surface.
Sprite::Sprite(SDL_Renderer* r, SDL_Surface* s) throw(HCException) {
    if (r == nullptr || s == nullptr)
        throw HCException("Cannot make a Sprite from a null renderer or surface.\n", HC_ASSET_EXCEPTION);

    SDL_Texture* tex = SDL_CreateTextureFromSurface(r, s);
    if (tex == nullptr)
        throw HCException("Cannot create a Sprite from a non-existent texture.\n", HC_ASSET_EXCEPTION);
    this->tex = tex;
}

// Loading a Sprite from a location on the disk.
Sprite::Sprite(SDL_Renderer* r, std::string path) throw(HCException) : Sprite(r, IMG_Load(path.c_str())) { }

// Destroying the sprite.
Sprite::~Sprite() {
    if (this->tex != NULL)
        SDL_DestroyTexture(this->tex);
}

// Accessing the underlying texture.
SDL_Texture* Sprite::getTexture() throw(HCException) {
    if (this->tex == nullptr)
        throw HCException("SDL texture has been destroyed.\n", HC_ASSET_EXCEPTION);
    return this->tex;
}
