//
// Created by yanny on 25/5/2019.
//

#ifndef HELLOWORLDC_SHIP_H
#define HELLOWORLDC_SHIP_H


#include "GraphicsManager.h"
#include "Sprite.h"

#include "SoundManager.h"
#include "Sound.h"

class Ship {
public:
    Ship(android_app* pApplication, GraphicsManager& pGraphicsManager, SoundManager& pSoundManager);
    void registerShip(Sprite* pGraphics, Sound* pCollisionSound);
    void initialize();
private:
    GraphicsManager& mGraphicsManager;
    SoundManager& mSoundManager;
    Sprite* mGraphics;
    Sound* mCollisionSound;
};
#endif //HELLOWORLDC_SHIP_H
