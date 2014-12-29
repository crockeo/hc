#include "keyboard.hpp"

//////////////
// Includes //
#include <SDL.h>

//////////
// Code //

// The set of key states.
const Uint8* keystates = nullptr;

// Updating the keyboard.
void keyboard::update() {
    keystates = SDL_GetKeyboardState(nullptr);
}

// Checking if the key states are ready.
bool keyboard::ready() { return keystates != nullptr; }

// Getting the state of a key.
bool keyboard::getKeyState(int index) {
    if (!keyboard::ready())
        return false;
    return keystates[index] == SDL_PRESSED;
}
