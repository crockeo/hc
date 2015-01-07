#ifndef _PLAYER_HPP_
#define _PLAYER_HPP_

//////////////
// Includes //
#include "../gamestate.hpp"
#include "../assets.hpp"
#include "../camera.hpp"
#include "../entity.hpp"
#include "../window.hpp"

//////////
// Code //

// The player class.
class Player : public Entity {
private:
    bool canJump;
    float dx, dy;

    // Colliding with a given rectangle.
    void collide(const Entity&);

    // Moving the player based on player input.
    bool input(float);

    // Decelerating the player.
    void decelerate(float, bool);

public:
    // Creating a player at a position.
    Player(float, float);

    // Overriding the update function.
    void update(const GameState&, float);

    // Overriding the render function.
    void render(Window&, const Camera&, const Assets&);
};

#endif
