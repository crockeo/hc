#ifndef _KEYBOARD_HPP_
#define _KEYBOARD_HPP_

//////////
// Code //

namespace keyboard {
    // Updating the keyboard.
    void update();

    // Checking if the key states are ready.
    bool ready();

    // Getting the state of a key.
    bool getKeyState(int);
}

#endif
