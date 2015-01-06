#include "block.hpp"

//////////
// Code //

// Creating a new block from a rectangle.
Block::Block(Rectangle r) : Entity(r) { }

// Rendering a given block.
void Block::render(Window& w, const Camera& c, const Assets& a) {
    a.spriteSheets.at("res/forest_tiles.png").blit(w, this->position.fTranslate(-c.x, -c.y), 0, 0);
}
