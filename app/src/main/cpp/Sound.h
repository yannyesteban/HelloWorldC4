//
// Created by Yanny on 2/6/2019.
//

#ifndef HELLOWORLDC2_SOUND_H
#define HELLOWORLDC2_SOUND_H


class SoundManager;
#include "Resource.h"
#include "Types.h"
class Sound {
public:
    Sound(android_app* pApplication, Resource* pResource);
    const char* getPath();
    uint8_t* getBuffer() { return mBuffer; };
    off_t getLength() { return mLength; };
    status load();
    status unload();
private:
    friend class SoundManager;
    Resource* mResource;
    uint8_t* mBuffer; off_t mLength;
};

#endif //HELLOWORLDC2_SOUND_H
