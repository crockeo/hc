#include "player.hpp"

//////////////
// Includes //
#include "../keyboard.hpp"
#include "tilemap.hpp"
#include "tile.hpp"

//////////
// Code //

const float MIN_SPEED =   5;
const float ACCEL     = 640;

// Checking if a value is near another value.
bool aroundNum(float target, float offset, float value) {
    return value < target + offset &&
           value > target - offset;
}

// Colliding with a given rectangle.
void Player::collide(const Entity& e) {
    Rectangle& src    = this->position;
    Rectangle  target = e.getPosition();

    switch (src.dirCollides(target)) {
    case COLLISION_TOP:
        if (this->dy <= 0) {
            src.y = target.bottom();
            this->dy = 0;
        }

        break;
    case COLLISION_BOTTOM:
        if (this->dy >= 0) {
            src.y = target.top() - src.h;
            onGround = true;
            this->dy = 0;
        }

        break;
    case COLLISION_LEFT:
        src.x = target.right();
        this->dx /= -2;
        break;
    case COLLISION_RIGHT:
        src.x = target.left() - src.w;
        this->dx /= -2;
        break;
    case COLLISION_NONE:
        break;
    }
}

// Moving the player based on player input.
bool Player::input(float dt) {
    bool mx = false;

    // Moving left.
    if (keyboard::getKeyState(SDL_SCANCODE_D)) {
        if (this->dx < 0)
            this->dx += 2 * ACCEL * dt;
        else
            this->dx += ACCEL * dt;
        mx = true;
    }

    // Moving right.
    if (keyboard::getKeyState(SDL_SCANCODE_A)) {
        if (this->dx > 0)
            this->dx -= 2 * ACCEL * dt;
        else
            this->dx -= ACCEL * dt;
        mx = true;
    }

    // Jumping.
    if (onGround && keyboard::getKeyState(SDL_SCANCODE_SPACE)) {
        onGround = false;
        this->dy = -400;
    }

    return mx;
}

// Decelerating the player.
void Player::decelerate(float dt, bool mx) {
    if (!mx) {
        if (this->dx > 0)
            this->dx -= ACCEL * dt;
        if (this->dx < 0)
            this->dx += ACCEL * dt;

        if (aroundNum(0, MIN_SPEED, this->dx))
            this->dx = 0;
    }
}

// Creating a player at a position.
Player::Player(float x, float y) :
        Entity(Rectangle(x, y, 100, 100)) {
    this->onGround = false;
    this->dx = 0;
    this->dy = 0;
}

// Overriding the update function.
void Player::update(const GameState& gs, float dt) {
    for (auto it = gs.blocks.begin(); it != gs.blocks.end(); it++)
        this->collide(*(*it));

    std::vector<Tile> tiles = ((TileMap*)gs.tilemap)->getTiles();
    for (auto it = tiles.begin(); it != tiles.end(); it++)
        this->collide(*it);

    this->decelerate(dt, this->input(dt));

    if (!onGround)
        this->dy += ACCEL * dt;

    this->position.translate(this->dx * dt, this->dy * dt);
}

// Overriding the render function.
void Player::render(Window& w, const Camera& c, const Assets& a) {
    a.animations.at("res/test.png").blit(w, this->position.fTranslate(-c.x, -c.y));
}
