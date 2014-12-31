#include "sprite.hpp"

//////////////
// Includes //
#include <SDL_image.h>
#include <SDL.h>

#include "rectangle.hpp"
#include "window.hpp"

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

// Copying the Sprite.
Sprite::Sprite(const Sprite& s) {
    this->tex = s.tex;
    this->original = false;
}

// Destroying the sprite.
Sprite::~Sprite() {
    if (this->tex != NULL && this->original)
        SDL_DestroyTexture(this->tex);
}

// Blitting this whole sprite.
void Sprite::blit(Window& w, Rectangle dst) {
    SDL_RenderCopy(w.getRenderer(),
                   this->tex,
                   nullptr,
                   &dst.sdlRect);
}

// Blitting a portion of this sprite.
void Sprite::blit(Window& w, Rectangle dst, Rectangle src) {
    SDL_RenderCopy(w.getRenderer(),
                   this->tex,
                   &src.sdlRect,
                   &dst.sdlRect);
}
