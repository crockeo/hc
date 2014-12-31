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

// A class to represent a map between strings and different sets of assets.
class Assets {
private:
    std::unordered_map<std::string, Sprite*> sprites;

public:
    // Deleting the copy constructor.
    Assets(const Assets&) = delete;

    // The default constructor.
    Assets();

    // Destroying all of the assets.
    ~Assets();

    // Adding different types of assets.
    void addSprite(Window&, std::string);

    // Accessing different types of assets.
    Sprite getSprite(std::string) const;
};

// Loading the set of assets for the rest of the program.
void loadAssets(Window&, Assets&);

#endif
