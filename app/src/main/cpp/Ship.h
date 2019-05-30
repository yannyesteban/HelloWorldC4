//
// Created by yanny on 25/5/2019.
//

#ifndef HELLOWORLDC_SHIP_H
#define HELLOWORLDC_SHIP_H


#include "GraphicsManager.h"
#include "Sprite.h"
class Ship {
public:
    Ship(android_app* pApplication, GraphicsManager& pGraphicsManager);
    void registerShip(Sprite* pGraphics);
    void initialize();
private:
    GraphicsManager& mGraphicsManager;
    Sprite* mGraphics;
};
#endif //HELLOWORLDC_SHIP_H
