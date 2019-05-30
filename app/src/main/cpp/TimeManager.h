//
// Created by yanny on 26/5/2019.
//

#ifndef HELLOWORLDC_TIMEMANAGER_H
#define HELLOWORLDC_TIMEMANAGER_H


#include "Types.h"
#include <ctime>
class TimeManager {
public:
    TimeManager();
    void reset();
    void update();
    double now();
    float elapsed() { return mElapsed; };
    float elapsedTotal() { return mElapsedTotal; };
private:
    double mFirstTime;
    double mLastTime;
    float mElapsed;
    float mElapsedTotal;
};
#endif //HELLOWORLDC_TIMEMANAGER_H
