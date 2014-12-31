#include "assets.hpp"

//////////////
// Includes //
#include <tuple>

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

// Accessing different types of assets.
Sprite Assets::getSprite(std::string name) const {
    Sprite s = *this->sprites.at(name);
    return s;
}

// Loading the set of assets for the rest of the program.
void loadAssets(Window& w, Assets& a) {
    a.addSprite(w, "res/test.png");
    a.addSprite(w, "res/forest_tiles.png");
}
