#include "player.hpp"

//////////////
// Includes //
#include "keyboard.hpp"

//////////
// Code //

const float MIN_SPEED =   5;
const float ACCEL     = 200;

// Checking if a value is near another value.
bool aroundNum(float target, float offset, float value) {
    return value < target + offset &&
           value > target - offset;
}

// Creating a player at a position.
Player::Player(float x, float y) : Entity(Rectangle(x, y, 50, 50)) {
    this->onGround = false;
    this->dx = 0;
    this->dy = 0;
}

// Overriding the update function.
void Player::update(const GameState& gs, float dt) {
    bool mx = false;

    if (keyboard::getKeyState(SDL_SCANCODE_D)) {
        if (dx < 0)
            dx += 2 * ACCEL * dt;
        else
            dx += ACCEL * dt;
        mx = true;
    }

    if (keyboard::getKeyState(SDL_SCANCODE_A)) {
        if (dx > 0)
            dx -= 2 * ACCEL * dt;
        else
            dx -= ACCEL * dt;
        mx = true;
    }

    if (!mx) {
        if (dx > 0)
            dx -= ACCEL * dt;
        if (dx < 0)
            dx += ACCEL * dt;

        if (aroundNum(0, MIN_SPEED, dx))
            dx = 0;
    }

    this->position.translate(this->dx * dt, this->dy * dt);
}

// Overriding the render function.
void Player::render(Window& w, const Camera& c, const Assets& a) {
    a.animations.at("res/test.png").blit(w, this->position.fTranslate(-c.x, -c.y));
}
