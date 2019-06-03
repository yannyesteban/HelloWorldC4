//
// Created by Yanny on 2/6/2019.
//

#ifndef HELLOWORLDC2_SOUNDMANAGER_H
#define HELLOWORLDC2_SOUNDMANAGER_H

#include "Sound.h"
#include "SoundQueue.h"

#include "Types.h"
#include <android_native_app_glue.h>
#include <SLES/OpenSLES.h>
#include <SLES/OpenSLES_Android.h>
class SoundManager {
public:
    SoundManager(android_app* pApplication);
    ~SoundManager();
    status start();
    void stop();

    status playBGM(Resource& pResource);
    void stopBGM();

    Sound* registerSound(Resource& pResource);
    void playSound(Sound* pSound);
private:
    android_app* mApplication;
    SLObjectItf mEngineObj; SLEngineItf mEngine;
    SLObjectItf mOutputMixObj;

    SLObjectItf mBGMPlayerObj; SLPlayItf mBGMPlayer;
    SLSeekItf mBGMPlayerSeek;

    static const int32_t QUEUE_COUNT = 4;
    SoundQueue mSoundQueues[QUEUE_COUNT]; int32_t mCurrentQueue;
    Sound* mSounds[32]; int32_t mSoundCount;
};

#endif //HELLOWORLDC2_SOUNDMANAGER_H
