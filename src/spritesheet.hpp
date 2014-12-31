#ifndef _SPRITE_SHEET_HPP_
#define _SPRITE_SHEET_HPP_

//////////////
// Includes //
#include "hcexception.hpp"
#include "sprite.hpp"

//////////
// Code //

// A type to specifically represent multiple sprites on a single texture.
class SpriteSheet {
private:
    Sprite* sprite;
    int cols , rows;
    int width, height;
    bool original;

    // Initializing the SpriteSheet sizes.
    void init(int, int, int, int);

public:
    // Making a SpriteSheet from an existing SDL_Texture.
    SpriteSheet(SDL_Texture*, int, int, int, int) throw(HCException);

    // Making a SpriteSheet from an SDL_Surface.
    SpriteSheet(SDL_Renderer*, SDL_Surface*, int, int, int, int) throw(HCException);

    // Loading a SpriteSheet from a location on the disk.
    SpriteSheet(SDL_Renderer*, std::string, int, int, int, int) throw(HCException);

    // The copy constructor.
    SpriteSheet(const SpriteSheet&);

    // Destroying the SpriteSheet.
    ~SpriteSheet();

    // Blitting a specific tile.
    void blit(Window&, Rectangle, int, int) const;
};

#endif
