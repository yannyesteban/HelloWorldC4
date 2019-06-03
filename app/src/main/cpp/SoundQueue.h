//
// Created by Yanny on 2/6/2019.
//

#ifndef HELLOWORLDC2_SOUNDQUEUE_H
#define HELLOWORLDC2_SOUNDQUEUE_H


#include "Sound.h"
#include <SLES/OpenSLES.h>
#include <SLES/OpenSLES_Android.h>
class SoundQueue {
public:
    SoundQueue();
    status initialize(SLEngineItf pEngine, SLObjectItf pOutputMixObj);
    void finalize();
    void playSound(Sound* pSound);
private:
    SLObjectItf mPlayerObj; SLPlayItf mPlayer;
    SLBufferQueueItf mPlayerQueue;
};


#endif //HELLOWORLDC2_SOUNDQUEUE_H
