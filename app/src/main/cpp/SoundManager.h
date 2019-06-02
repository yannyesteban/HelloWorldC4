//
// Created by Yanny on 2/6/2019.
//

#ifndef HELLOWORLDC2_SOUNDMANAGER_H
#define HELLOWORLDC2_SOUNDMANAGER_H

#include "Types.h"
#include <android_native_app_glue.h>
#include <SLES/OpenSLES.h>
class SoundManager {
public:
    SoundManager(android_app* pApplication);
    status start();
    void stop();
private:
    android_app* mApplication;
    SLObjectItf mEngineObj; SLEngineItf mEngine;
    SLObjectItf mOutputMixObj;
};

#endif //HELLOWORLDC2_SOUNDMANAGER_H
