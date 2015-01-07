#include "tilemap.hpp"

//////////
// Code //

// Constructing an empty set of tiles.
TileMap::TileMap() { }

// Adding a new Tile to the TileMap.
void TileMap::addTile(Tile t) { this->tiles.push_back(t); }

// Rendering every single tile in a tile map.
void TileMap::render(Window& w, const Camera& c, const Assets& a) {
    for (auto it = this->tiles.begin(); it != this->tiles.end(); it++)
        it->render(w, c, a);
}

// Accessing a copy of the tiles.
std::vector<Tile> TileMap::getTiles() { return this->tiles; }
