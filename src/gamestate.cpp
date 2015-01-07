#include "gamestate.hpp"

//////////////
// Includes //
#include "entities/tilemap.hpp"
#include "entities/player.hpp"
#include "entities/block.hpp"
#include "entities/tile.hpp"
#include "rectangle.hpp"

//////////
// Code //

// Constructing a default game state.
GameState::GameState() :
        position(0, 0, 100, 100) {
    this->blocks.push_back((Entity*)new Block(Rectangle(2, 400, 20, 80)));
    this->blocks.push_back((Entity*)new Block(Rectangle(-1000, 480, 2000, 10)));

    // Setting up the tile map.
    TileMap* tm = new TileMap();
    tm->addTile(Tile(HC_TILE_GRASS, 0, 4));
    tm->addTile(Tile(HC_TILE_GRASS, 1, 4));
    tm->addTile(Tile(HC_TILE_GRASS, 2, 5));
    tm->addTile(Tile(HC_TILE_GRASS, 6, 8));
    tm->addTile(Tile(HC_TILE_GRASS, 7, 9));

    this->tilemap = (Entity*)tm;
    this->player = new Player(0, 0);
}
