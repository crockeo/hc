#include "assets.hpp"

//////////////
// Includes //
#include <unordered_map>

#include "spritesheet.hpp"
#include "sprite.hpp"
#include "window.hpp"

//////////
// Code //

// The default constructor.
Assets::Assets() { }

// Loading the set of assets for the rest of the program.
void loadAssets(Window& w, Assets& a) {
    a.sprites.emplace(std::piecewise_construct,
                      std::make_tuple("res/test.png"),
                      std::make_tuple(w.getRenderer(), "res/test.png"));

    a.sprites.emplace(std::piecewise_construct,
                      std::make_tuple("res/forest_tiles.png"),
                      std::make_tuple(w.getRenderer(), "res/forest_tiles.png"));

    a.spriteSheets.emplace(std::piecewise_construct,
                           std::make_tuple("res/forest_tiles.png"),
                           std::make_tuple(w.getRenderer(), "res/forest_tiles.png", 15, 10, 16, 16));
}
