#ifndef _TILE_MAP_HPP_
#define _TILE_MAP_HPP_

//////////////
// Includes //
#include <istream>
#include <ostream>
#include <string>

#include "../assets.hpp"
#include "../camera.hpp"
#include "../entity.hpp"
#include "../window.hpp"
#include "tile.hpp"

//////////
// Code //

// The map of tiles in the game world.
class TileMap : Entity {
private:
    std::vector<std::vector<Tile>> tileLayers;

public:
    // Constructing an empty set of tiles.
    TileMap();

    // Adding a new Tile to the TileMap.
    void addTile(Tile);

    // Rendering every single tile in a tile map.
    void render(Window&, const Camera&, const Assets&);

    // Accessing a copy of the tiles.
    std::vector<Tile> getTiles(int) const;

    // Getting the collision layer.
    std::vector<Tile> getCollisionTiles() const;

    // Accessing the number of tiles.
    int layers() const;
};

// Loading a tile map from an istream.
TileMap loadTileMap(std::istream&);

// Loading a tile map from a location on disk.
TileMap loadTileMap(std::string);

// Writing a tile map to an ostream.
bool saveTileMap(std::ostream&, TileMap);

// Writing a tile map to a location on disk.
bool saveTileMap(std::string, TileMap);

#endif
