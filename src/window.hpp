#ifndef _WINDOW_HPP_
#define _WINDOW_HPP_

//////////////
// Includes //
#include <string>
#include <SDL.h>

#include "hcexception.hpp"

//////////
// Code //

// A class to represent an SDL window.
class Window {
private:
    SDL_Renderer* renderer;
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
    Window(std::string, int, int, bool) throw(HCException);

    // Destroying a window.
    ~Window();

    // Getting the pointer to the renderer.
    SDL_Renderer* getRenderer();

    // Getting the pointer to the window.
    SDL_Window* getWindow();

    // Getting the title.
    std::string getTitle() const;

    // Getting the size.
    int getWidth() const;
    int getHeight() const;

    // Checking if the window is full-screen.
    bool isFullscreen() const;

    // Checking if the window is in error.
    bool isError() const;
};

#endif
