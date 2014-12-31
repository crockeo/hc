#include "spritesheet.hpp"

//////////
// Code //

// Initializing the SpriteSheet sizes.
void SpriteSheet::init(int cols, int rows, int width, int height) {
    this->cols   = cols;
    this->rows   = rows;
    this->width  = width;
    this->height = height;
}

// Making a SpriteSheet from an existing SDL_Texture.
SpriteSheet::SpriteSheet(SDL_Texture* tex,
                         int cols , int rows,
                         int width, int height) throw(HCException) {
    this->sprite = new Sprite(tex);
    init(cols, rows, width, height);
}

// Making a SpriteSheet from an SDL_Surface.
SpriteSheet::SpriteSheet(SDL_Renderer* renderer, SDL_Surface* surf,
                         int cols , int rows,
                         int width, int height) throw(HCException) {
    this->sprite = new Sprite(renderer, surf);
    init(cols, rows, width, height);
}

// Loading a SpriteSheet from a location on the disk.
SpriteSheet::SpriteSheet(SDL_Renderer* renderer, std::string path,
                         int cols , int rows,
                         int width, int height) throw(HCException) {
    this->sprite = new Sprite(renderer, path);
    init(cols, rows, width, height);
}

// The copy constructor.
SpriteSheet::SpriteSheet(const SpriteSheet& ss) {
    this->sprite = ss.sprite;
    init(ss.rows, ss.cols, ss.width, ss.height);
    this->original = false;
}

// Destroying the SpriteSheet.
SpriteSheet::~SpriteSheet() {
    if (this->original)
        delete this->sprite;
}


// Blitting a specific tile.
void SpriteSheet::blit(Window& w, Rectangle dst, int x, int y) const {
    Rectangle r(x * this->width, y * this->height,
                    this->width,     this->height);

    this->sprite->blit(w, dst, r);
}

// Accessors
int SpriteSheet::getCols() const { return this->cols; }
int SpriteSheet::getRows() const { return this->rows; }
