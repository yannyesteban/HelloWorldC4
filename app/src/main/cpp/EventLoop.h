//
// Created by yanny on 25/5/2019.
//

#ifndef HELLOWORLDC_EVENTLOOP_H
#define HELLOWORLDC_EVENTLOOP_H
#include "ActivityHandler.h"
#include <android_native_app_glue.h>
class EventLoop {

public:
    EventLoop(android_app* pApplication, ActivityHandler& pActivityHandler);
    void run();
private:
    void activate();
    void deactivate();
    void processAppEvent(int32_t pCommand);
    static void callback_appEvent(android_app* pApplication, int32_t pCommand);
private:
    android_app* mApplication;
    bool mEnabled;
    bool mQuit;
public:
    ActivityHandler& mActivityHandler;
};
#endif //HELLOWORLDC_EVENTLOOP_H
