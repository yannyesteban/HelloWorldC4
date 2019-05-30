//
// Created by yanny on 26/5/2019.
//

#include "Log.h"
#include "TimeManager.h"
#include <cstdlib>
#include <time.h>
TimeManager::TimeManager():
        mFirstTime(0.0f),
        mLastTime(0.0f),
        mElapsed(0.0f),
        mElapsedTotal(0.0f) {
    srand(time(NULL));
}
void TimeManager::reset() {
    Log::info("Resetting TimeManager.");
    mElapsed = 0.0f;
    mFirstTime = now();
    mLastTime = mFirstTime;
}

double TimeManager::now() {
    timespec timeVal;
    clock_gettime(CLOCK_MONOTONIC, &timeVal);
    return timeVal.tv_sec + (timeVal.tv_nsec * 1.0e-9);
}

void TimeManager::update() {
    double currentTime = now();
    mElapsed = (currentTime - mLastTime);
    mElapsedTotal = (currentTime - mFirstTime);
    mLastTime = currentTime;
}