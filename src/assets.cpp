#include "assets.hpp"

//////////////
// Includes //
#include <unordered_map>
#include <vector>
#include <tuple>

#include "sprite.hpp"
#include "window.hpp"

//////////
// Code //

//// A class to represent a map between strings and different sets of assets.
//class Assets {
//private:
    //std::vector<std::tuple<std::string, AssetType>> bufferedLoads;
    //std::unorder_map<std::string, Sprite> sprites;

//public:

// Creating a set of assets from an already-created list of loads.
Assets::Assets(std::vector<std::tuple<std::string, AssetType>> bufferedLoads) {
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

// Performing the set of asset loads.
void Assets::performLoads(const Window& w) throw(HCException) {
    // TODO: Stuff here.
}

// Accessing a Sprite.
Sprite Assets::getSprite(std::string name) { return *this->sprites[name]; }
