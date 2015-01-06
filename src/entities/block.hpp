#ifndef _BLOCK_HPP_
#define _BLOCK_HPP_

//////////////
// Includes //
#include "../rectangle.hpp"
#include "../assets.hpp"
#include "../camera.hpp"
#include "../entity.hpp"

//////////
// Code //

// A type to represent a static block in the world.
class Block : Entity {
public:
    // Creating a new block from a rectangle.
    Block(Rectangle);

    // Rendering a given block.
    void render(Window&, const Camera&, const Assets&);
};

#endif
