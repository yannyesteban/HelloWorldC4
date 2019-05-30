//
// Created by yanny on 25/5/2019.
//

#include "Log.h"
#include "Ship.h"
#include "Types.h"

static const float INITAL_X = 0.5f;
static const float INITAL_Y = 0.25f;

Ship::Ship(android_app* pApplication, GraphicsManager& pGraphicsManager) :
        mGraphicsManager(pGraphicsManager),
        mGraphics(nullptr) {
}

void Ship::registerShip(Sprite* pGraphics) {
    mGraphics = pGraphics;
}

void Ship::initialize() {
    mGraphics->location.x = INITAL_X * mGraphicsManager.getRenderWidth();
    mGraphics->location.y = INITAL_Y * mGraphicsManager.getRenderHeight();
}