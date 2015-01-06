#ifndef _GAME_STATE_HPP_
#define _GAME_STATE_HPP_

//////////////
// Includes //
#include <unordered_map>
#include <string>
#include <vector>

#include "rectangle.hpp"
#include "camera.hpp"
#include "entity.hpp"
#include "timer.hpp"

//////////
// Code //

class Entity;

// A class to house the current state of the game.
struct GameState {
    // Constructing a default game state.
    GameState();

    Camera cam;

    std::unordered_map<std::string, Timer&> timers;

    Rectangle position;

    std::vector<Entity*> blocks;

    Entity* player;
};

#endif
