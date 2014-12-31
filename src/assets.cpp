#include "assets.hpp"

//////////////
// Includes //
#include <tuple>

#include "spritemap.hpp"
#include "sprite.hpp"
#include "window.hpp"

//////////
// Code //

// Performing a single asset load.
void Assets::performLoad(Window& w, std::tuple<std::string, AssetType> pair) throw(HCException) {
    std::string path = std::get<0>(pair);
    switch (std::get<1>(pair)) {
    // Loading a Sprite.
    case HC_SPRITE_ASSET:
        this->sprites[path] = new Sprite(w.getRenderer(), path);
        break;
    // Loading a SpriteMap.
    case HC_SPRITE_MAP_ASSET:
        // TODO: Find out how to load sprite maps.
        break;
    }
}

// Creating a set of assets from an already-created list of loads.
Assets::Assets(std::queue<std::tuple<std::string, AssetType>> bufferedLoads) {
    this->bufferedLoads = bufferedLoads;
}

// Creating an empty set of assets.
Assets::Assets() { }

// Destroying all of the assets.
Assets::~Assets() {
    for (auto it = this->sprites.begin(); it != this->sprites.end(); it++) {
        delete std::get<1>(*it);
    }
}
// Inserting an asset load.
void Assets::addAssetLoad(std::string path, AssetType type) {
    this->bufferedLoads.push(std::make_tuple(path, type));
}

// Performing the set of asset loads.
void Assets::performLoads(Window& w) throw(HCException) {
    while (!this->bufferedLoads.empty()) {
        std::tuple<std::string, AssetType> pair = this->bufferedLoads.front();
        this->bufferedLoads.pop();

        this->performLoad(w, pair);
    }
}

// Accessing a Sprite.
Sprite Assets::getSprite(std::string name) const {
    Sprite s = *this->sprites.at(name);
    return s;
}

// Accessing a SpriteMap.
SpriteMap Assets::getSpriteMap(std::string name) const {
    SpriteMap sm = *this->spriteMaps.at(name);
    return sm;
}
