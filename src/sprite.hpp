#ifndef _SPRITE_HPP_
#define _SPRITE_HPP_

//////////////
// Includes //
#include <SDL.h>

#include "hcexception.hpp"
#include "rectangle.hpp"
#include "window.hpp"

//////////
// Code //

// A class to represent a Sprite.
class Sprite {
private:
    SDL_Texture* tex;
    bool original;

public:
    // Making a Sprite from an existing SDL_Texture.
    Sprite(SDL_Texture*) throw(HCException);

    // Making a Sprite from an SDL_Surface.
    Sprite(SDL_Renderer*, SDL_Surface*) throw(HCException);

    // Loading a Sprite from a location on the disk.
    Sprite(SDL_Renderer*, std::string) throw(HCException);

    // Copying the Sprite.
    Sprite(const Sprite&);

    // Destroying the sprite.
    ~Sprite();

    // Blitting this whole sprite.
    void blit(Window&, Rectangle) const;

    // Blitting a portion of this sprite.
    void blit(Window&, Rectangle, Rectangle) const;
};

#endif
