#include "window.hpp"

//////////////
// Includes //
#include <SDL.h>

//////////
// Code //

// Creating a new window.
Window::Window(std::string title, int width, int height, bool fullscreen) {
    this->title      = title;
    this->width      = width;
    this->height     = height;
    this->fullscreen = fullscreen;
    this->error      = false;

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        this->error = true;
        return;
    }

    this->window = SDL_CreateWindow(
        title.c_str(),
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        width, height,
        fullscreen ? SDL_WINDOW_SHOWN | SDL_WINDOW_FULLSCREEN : SDL_WINDOW_SHOWN
    );

    if (this->window == nullptr) {
        this->error = true;
        SDL_Quit();
        return;
    }

    this->renderer = SDL_CreateRenderer(
        this->window,
        0,
        SDL_RENDERER_ACCELERATED
    );

    if (this->renderer == nullptr) {
        this->error = true;
        SDL_DestroyWindow(this->window);
        SDL_Quit();
        return;
    }
}

// Destroying a window.
Window::~Window() {
    if (!this->error) {
        SDL_DestroyRenderer(this->renderer);
        SDL_DestroyWindow(this->window);
        SDL_Quit();
    }
}
