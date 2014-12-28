#ifndef _ASSETS_HPP_
#define _ASSETS_HPP_

//////////////
// Includes //
#include <unordered_map>
#include <queue>
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
    std::queue<std::tuple<std::string, AssetType>> bufferedLoads;
    std::unordered_map<std::string, Sprite*> sprites;

    // Performing a single asset load.
    void performLoad(Window&, std::tuple<std::string, AssetType>) throw(HCException);

public:
    // Deleting the copy constructor.
    Assets(const Assets&) = delete;

    // Creating a set of assets from an already-created list of loads.
    Assets(std::queue<std::tuple<std::string, AssetType>>);

    // Creating an empty set of assets.
    Assets();

    // Destroying all of the assets.
    ~Assets();

    // Inserting an asset load.
    void addAssetLoad(std::string, AssetType);

    // Performing the set of asset loads.
    void performLoads(Window&) throw(HCException);

    // Accessing a Sprite.
    Sprite getSprite(std::string);
};

#endif
