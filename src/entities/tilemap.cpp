#include "tilemap.hpp"

//////////
// Code //

// Constructing an empty set of tiles.
TileMap::TileMap() { }

// Adding a new Tile to the TileMap.
void TileMap::addTile(Tile t) {
    while (this->tileLayers.size() < t.getLayer())
        this->tileLayers.push_back(std::vector<Tile>());
    this->tileLayers[t.getLayer() - 1].push_back(t);
}

// Rendering every single tile in a tile map.
void TileMap::render(Window& w, const Camera& c, const Assets& a) {
    for (int i = this->tileLayers.size() - 1; i >= 0; i--) {
        for (auto it = this->tileLayers[i].begin(); it != this->tileLayers[i].end(); it++)
            it->render(w, c, a);
    }
}

// Accessing a copy of the tiles.
std::vector<Tile> TileMap::getTiles(int layer) {
    return this->tileLayers[layer - 1];
}

// Getting the collision layer.
std::vector<Tile> TileMap::getCollisionTiles() { return this->getTiles(1); }
