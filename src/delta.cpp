#include "delta.hpp"

//////////////
// Includes //
#include <chrono>

//////////
// Code //

// Getting the current system time in milliseconds.
int getTimeMillis() {
    auto now = std::chrono::system_clock::now();
    return std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()).count();
}

//// A utility to do some delta timing stuff.
//class Delta {
//private:
    //int last, curr;
    //bool first;

//public:

// Constructing a delta.
Delta::Delta() {
    this->last = 0;
    this->curr = 0;
    this->first = true;
}

// Getting the time since the last time this was run.
float Delta::since() {
    curr = getTimeMillis();
    float dt = (curr - last) / 1000.f;
    last = curr;

    if (this->first) {
        this->first = false;
        return 0;
    }

    return dt;
}

//};
