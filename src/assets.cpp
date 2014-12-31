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
    //a.spriteSheets.emplace("res/forest_tiles.png", w.getRenderer(), "res/forest_tiles.png", 15, 10, 16, 16);
    //a.sprites.emplace(std::piecewise_construct, "res/forest_tiles.png", w.getRenderer(), "res/test.png");
    //a.sprites.insert("res/test.png", new Sprite(w.getRenderer(), "res/test.png"));
}
