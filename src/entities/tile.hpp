#ifndef _TILE_HPP_
#define _TILE_HPP_

//////////////
// Includes //
#include "../assets.hpp"
#include "../camera.hpp"
#include "../entity.hpp"
#include "../window.hpp"

//////////
// Code //

#define HC_TILE_WIDTH  50
#define HC_TILE_HEIGHT 50

// A set of tile types.
enum TileType {
    HC_TILE_GRASS
};

// Representing a single tile in the world.
class Tile : public Entity {
private:
    TileType type;
    int x, y;

public:
    // Creating a new tile type at a given location.
    Tile(TileType, int, int);

    // Rendering the tile.
    void render(Window&, const Camera&, const Assets&);
};

#endif
