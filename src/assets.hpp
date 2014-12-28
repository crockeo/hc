#ifndef _ASSETS_HPP_
#define _ASSETS_HPP_

//////////////
// Includes //
#include <unordered_map>
#include <vector>
#include <tuple>

#include "sprite.hpp"
#include "window.hpp"

//////////
// Code //

// An enum to represent the a set of asset types.
enum AssetType {
    HC_SPRITE_ASSET
};

// A class to represent a map between strings and different sets of assets.
class Assets {
private:
    std::vector<std::tuple<std::string, AssetType>> bufferedLoads;
    std::unordered_map<std::string, Sprite*> sprites;

public:
    // Deleting the copy constructor.
    Assets(const Assets&) = delete;

    // Creating a set of assets from an already-created list of loads.
    Assets(std::vector<std::tuple<std::string, AssetType>>);

    // Creating an empty set of assets.
    Assets();

    // Destroying all of the assets.
    ~Assets();

    // Performing the set of asset loads.
    void performLoads(const Window&) throw(HCException);

    // Accessing a Sprite.
    Sprite getSprite(std::string);
};

#endif
