#include "timer.hpp"

//////////////
// Includes //
#include "delta.hpp"

//////////
// Code //

// Constructing a timer with a cap.
Timer::Timer(float cap) {
    this->running = false;
    this->accum = 0;
    this->cap = cap;
}

// Constructing a default timer.
Timer::Timer() {
    this->running = false;
    this->accum = 0;
    this->cap = 0;
}

// Starting the timer.
void Timer::start() {
    if (!this->running)
        this->running = true;
}

// Stopping the timer (such that if it's 
void Timer::stop() {
    if (this->running)
        this->running = false;
}

// Resetting the accumulated time.
void Timer::reset() {
    this->accum = 0;
}

// Updating the timer.
void Timer::update() {
    if (this->cap != 0)
        if (this->accum > this->cap)
            this->accum -= this->cap;
    if (this->running)
        this->accum += this->delta.since();
}

// Getting the time since the timer was started.
float Timer::getTime() const { return this->accum; }

// Checking if the timer is running.
bool Timer::isRunning() const { return this->running; }
