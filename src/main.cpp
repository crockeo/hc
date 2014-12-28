//////////////
// Includes //
#include <SDL_image.h>
#include <SDL.h>

#include "window.hpp"

//////////
// Code //

// Loading an image from the disk.
SDL_Texture* loadImage(Window& w, std::string path) {
    SDL_Surface* img = IMG_Load(path.c_str());
    if (img == nullptr)
        return nullptr;

    SDL_Texture* tex = SDL_CreateTextureFromSurface(
        w.getRenderer(),
        img
    );

    SDL_FreeSurface(img);
    return tex;
}

// Entry point!
int main() {
    Window w("Hello World!", 640, 480, false);

    SDL_Texture* tex = loadImage(w, "res/test.png");
    if (tex == nullptr) {
        return 1;
    }

    SDL_RenderCopy(w.getRenderer(),
                   tex,
                   nullptr,
                   nullptr);
    SDL_RenderPresent(w.getRenderer());

    SDL_Event e;
    while (SDL_WaitEvent(&e)) {
        if (e.type == SDL_QUIT)
            break;
    }

    return 0;
}
