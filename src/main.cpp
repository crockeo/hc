//////////////
// Includes //
#include <SDL.h>
#include <iostream>

//////////
// Code //

// Entry point!
int main() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cout << "Failed to initialize SDL." << std::endl;
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow(
        "Horizontally Challenged",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        640, 480,
        SDL_WINDOW_SHOWN
    );

    if (window == nullptr) {
        std::cout << "Failed to open an SDL_Window." << std::endl;
        SDL_Quit();
        return 1;
    }

    SDL_Event e;
    while (SDL_WaitEvent(&e)) {
        if (e.type == SDL_QUIT)
            break;
    }

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
