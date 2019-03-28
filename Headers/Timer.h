//
// Created by xxzxcuzx_me on 12.03.19.
//

#ifndef SDIZO1_TIMER_H
#define SDIZO1_TIMER_H

#include <chrono>

class Timer {
public:
    std::chrono::high_resolution_clock::time_point startTime;
    std::chrono::high_resolution_clock::time_point endTime;

    void start();
    void stop();
    long getDuration();
};


#endif //SDIZO1_TIMER_H
