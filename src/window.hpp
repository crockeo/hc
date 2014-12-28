#ifndef _WINDOW_HPP_
#define _WINDOW_HPP_

//////////////
// Includes //
#include <string>
#include <SDL.h>

//////////
// Code //

// A class to represent an SDL window.
class Window {
private:
    SDL_Window* window;
    std::string title;
    int width, height;
    bool fullscreen;
    SDL_Event event;
    bool error;

public:
    // Removing the copy constructor.
    Window(const Window&) = delete;

    // Creating a new window.
    Window(std::string, int, int, bool);

    // Destroying a window.
    ~Window();
};

#endif
