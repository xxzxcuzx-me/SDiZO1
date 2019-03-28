//
// Created by xxzxcuzx_me on 12.03.19.
//

#include "Timer.h"

void Timer::start() {
    startTime = std::chrono::high_resolution_clock::now();
}

void Timer::stop() {
    endTime = std::chrono::high_resolution_clock::now();
}

long Timer::getDuration() {
    return std::chrono::duration_cast<std::chrono::nanoseconds>(endTime-startTime).count();
}