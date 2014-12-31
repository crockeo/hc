#include "assets.hpp"

//////////////
// Includes //
#include <tuple>

#include "spritemap.hpp"
#include "sprite.hpp"
#include "window.hpp"

//////////
// Code //

// The default constructor.
Assets::Assets() { }

// Destroying all of the assets.
Assets::~Assets() {
    for (auto it = this->sprites.begin(); it != this->sprites.end(); it++) {
        delete std::get<1>(*it);
    }
}

// Adding different types of assets.
void Assets::addSprite(Window& w, std::string path) {
    this->sprites[path] = new Sprite(w.getRenderer(), path);
}

void Assets::addSpriteMap(Window& w, std::string path, int cols, int rows, int width, int height) {
    this->spriteMaps[path] = new SpriteMap(w, path, cols, rows, width, height);
}

// Accessing different types of assets.
Sprite Assets::getSprite(std::string name) const {
    Sprite s = *this->sprites.at(name);
    return s;
}

SpriteMap Assets::getSpriteMap(std::string name) const {
    SpriteMap sm = *this->spriteMaps.at(name);
    return sm;
}

// Loading the set of assets for the rest of the program.
void loadAssets(Window& w, Assets& a) {
    a.addSprite(w, "res/test.png");
    a.addSpriteMap(w, "res/forest_tiles.png", 15, 10, 16, 16);
}
