#ifndef _ASSETS_HPP_
#define _ASSETS_HPP_

//////////////
// Includes //
#include <unordered_map>

#include "spritesheet.hpp"
#include "sprite.hpp"

//////////
// Code //

// A container for a set of assets.
struct Assets {
    std::unordered_map<std::string, SpriteSheet> spriteSheets;
    std::unordered_map<std::string, Sprite> sprites;

    // The default constructor.
    Assets();

    // Deleting the copy constructor.
    Assets(const Assets&) = delete;
};

// Loading the set of assets for the rest of the program.
void loadAssets(Window&, Assets&);

#endif
