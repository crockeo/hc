#ifndef _TIMER_HPP_
#define _TIMER_HPP_

//////////////
// Includes //
#include "delta.hpp"

//////////
// Code //

// A class to keep track of time.
class Timer {
private:
    bool running;
    float accum;
    Delta delta;

public:
    // Constructing a default timer.
    Timer();

    // Starting the timer.
    void start();

    // Stopping the timer (such that if it's 
    void stop();

    // Resetting the accumulated time.
    void reset();

    // Updating the timer.
    void update();

    // Getting the time since the timer was started.
    float getTime() const;

    // Checking if the timer is running.
    bool isRunning() const;
};

#endif
