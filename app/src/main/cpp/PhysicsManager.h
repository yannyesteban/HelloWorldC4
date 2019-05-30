//
// Created by yanny on 26/5/2019.
//

#ifndef HELLOWORLDC_PHYSICSMANAGER_H
#define HELLOWORLDC_PHYSICSMANAGER_H


#include "GraphicsManager.h"
#include "TimeManager.h"
#include "Types.h"
struct PhysicsBody {
    PhysicsBody(Location* pLocation, int32_t pWidth, int32_t pHeight):
            location(pLocation),

            width(pWidth), height(pHeight),
            velocityX(0.0f), velocityY(0.0f) {
    }
    Location* location;
    int32_t width; int32_t height;
    float velocityX; float velocityY;
};

class PhysicsManager {
public:
    PhysicsManager(TimeManager& pTimeManager,
                   GraphicsManager& pGraphicsManager);
    ~PhysicsManager();
    PhysicsBody* loadBody(Location& pLocation, int32_t pWidth,
                          int32_t pHeight);
    void update();
private:
    TimeManager& mTimeManager;
    GraphicsManager& mGraphicsManager;
    PhysicsBody* mPhysicsBodies[1024]; int32_t
            mPhysicsBodyCount;
};


#endif //HELLOWORLDC_PHYSICSMANAGER_H
