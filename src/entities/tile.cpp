#include "tile.hpp"

//////////
// Code //

// Creating a new tile type at a given location.
Tile::Tile(TileType t, int x, int y) :
        Entity(Rectangle(x * HC_TILE_WIDTH, y * HC_TILE_HEIGHT,
                             HC_TILE_WIDTH,     HC_TILE_HEIGHT)) {
    this->type = t;
    this->x = x;
    this->y = y;
}

// Rendering the tile.
void Tile::render(Window& w, const Camera& c, const Assets& a) {
    switch (this->type) {
    case HC_TILE_GRASS:
        a.spriteSheets.at("res/forest_tiles.png").blit(w, this->position.fTranslate(-c.x, -c.y), 0, 0);
        break;
    }
}
