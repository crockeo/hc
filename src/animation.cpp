#include "animation.hpp"

//////////////
// Includes //
#include <vector>
#include <tuple>

#include "spritesheet.hpp"
#include "rectangle.hpp"
#include "window.hpp"

//////////
// Code //

// Determining the index of order for a given time.
int Animation::determineIndex(float time) const {
    return (int)(time / this->frameTime);
}

// Constructing an animation from all required info.
Animation::Animation(SpriteSheet ss, std::vector<std::tuple<int, int>> order, float frameTime, bool repeats) : sheet(ss) {
    this->order     = order;
    this->frameTime = frameTime;
    this->repeats   = repeats;
}

// Constructing an animation with the default ordering (top left to bottom
// right, by row.)
Animation::Animation(SpriteSheet ss, float frameTime, bool repeats) : sheet(ss) {
    for (int row = 0; row < this->sheet.getRows(); row++)
        for (int col = 0; col < this->sheet.getCols(); col++)
            this->order.push_back(std::make_tuple(col, row));

    this->frameTime = frameTime;
    this->repeats   = repeats;
}

// Getting the timer that belongs to this Animation.
Timer& Animation::getTimer() { return this->timer; }

// Rendering a specific frame in an animation.
void Animation::blit(Window& w, Rectangle dst, int frame) const {
    auto pos = this->order[frame];
    this->sheet.blit(w, dst, std::get<0>(pos), std::get<1>(pos));
}

// Rendering an animation's current frame.
void Animation::blit(Window& w, Rectangle dst) const {
    // TODO: Determine the current time.
    this->blit(w, dst, this->determineIndex(this->timer.getTime()));
}
