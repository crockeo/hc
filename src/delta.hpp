#ifndef _DELTA_HPP_
#define _DELTA_HPP_

//////////
// Code //

// Getting the current system time in milliseconds.
int getTimeMillis();

// A utility to do some delta timing stuff.
class Delta {
private:
    int last, curr;
    bool first;

public:
    // Constructing a delta.
    Delta();

    // Getting the time since the last time this was run.
    float since();
};

#endif
