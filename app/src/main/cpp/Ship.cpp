//
// Created by yanny on 25/5/2019.
//

#include "Log.h"
#include "Ship.h"
#include "Types.h"

static const float INITAL_X = 0.5f;
static const float INITAL_Y = 0.25f;

Ship::Ship(android_app* pApplication, GraphicsManager& pGraphicsManager,SoundManager& pSoundManager) :
        mGraphicsManager(pGraphicsManager),
        mGraphics(nullptr),
        mSoundManager(pSoundManager),
        mCollisionSound(nullptr){
}

void Ship::registerShip(Sprite* pGraphics, Sound* pCollisionSound) {
    mGraphics = pGraphics;
    mCollisionSound = pCollisionSound;
}
void Ship::initialize() {
    mGraphics->location.x = INITAL_X * mGraphicsManager.getRenderWidth();
    mGraphics->location.y = INITAL_Y * mGraphicsManager.getRenderHeight();
    mSoundManager.playSound(mCollisionSound);
}