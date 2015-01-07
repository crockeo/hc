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

    this->tilemap = (Entity*)new TileMap(loadTileMap("res/tilemap.tm"));
    this->player = new Player(0, 0);
}
