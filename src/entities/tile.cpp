#include "tile.hpp"

//////////
// Code //


// Creating a new tile type at a given location and layer.
Tile::Tile(TileType t, int layer, int x, int y) :
        Entity(Rectangle(x * HC_TILE_WIDTH, y * HC_TILE_HEIGHT,
                             HC_TILE_WIDTH,     HC_TILE_HEIGHT)) {
    this->type = t;
    this->layer = layer;
    this->x = x;
    this->y = y;
}


// Creating a new tile on the first layer at a given location.
Tile::Tile(TileType t, int x, int y) :
        Entity(Rectangle(x * HC_TILE_WIDTH, y * HC_TILE_HEIGHT,
                             HC_TILE_WIDTH,     HC_TILE_HEIGHT)) {
    this->type = t;
    this->layer = 1;
    this->x = x;
    this->y = y;
}

// Rendering the tile.
void Tile::render(Window& w, const Camera& c, const Assets& a) {
    float scale = this->layer == 1 ? 1 : 1 + (this->layer / 50.f);
    Rectangle pos = this->position.fTranslate(-c.x / scale, -c.y / scale);

    switch (this->type) {
    case HC_TILE_GRASS:
        a.spriteSheets.at("res/forest_tiles.png").blit(w, pos, 0, 0);
        break;
    case HC_TILE_DARK:
        a.spriteSheets.at("res/forest_tiles.png").blit(w, pos, 1, 0);
        break;
    case HC_TILE_WOOD:
        a.sprites.at("res/wood1.jpg").blit(w, pos);
        break;
    }
}

// Getting the type of this tile.
TileType Tile::getType() const { return this->type; }

// Getting the layer of the tile.
int Tile::getLayer() const { return this->layer; }

// Getting the X & Y coordinates of the tile.
int Tile::getTX() const { return this->x; }
int Tile::getTY() const { return this->y; }
