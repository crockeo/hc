#include "timer.hpp"

//////////////
// Includes //
#include "delta.hpp"

//////////
// Code //

// Constructing a default timer.
Timer::Timer() {
    this->running = false;
    this->accum = 0;
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
    if (this->running)
        this->accum += this->delta.since();
}

// Getting the time since the timer was started.
float Timer::getTime() const { return this->accum; }

// Checking if the timer is running.
bool Timer::isRunning() const { return this->running; }
