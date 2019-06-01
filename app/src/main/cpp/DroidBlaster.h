//
// Created by yanny on 25/5/2019.
//

#ifndef HELLOWORLDC_DROIDBLASTER_H
#define HELLOWORLDC_DROIDBLASTER_H

#include "ActivityHandler.h"
#include "Asteroid.h"
#include "EventLoop.h"
#include "GraphicsManager.h"
#include "PhysicsManager.h"
#include "Resource.h"
#include "Ship.h"
#include "SpriteBatch.h"
#include "StarField.h"
#include "TimeManager.h"
#include "Types.h"
class DroidBlaster : public ActivityHandler {
public:
    DroidBlaster(android_app* pApplication);
    void run();
private:
    TimeManager mTimeManager;
    GraphicsManager mGraphicsManager;
    PhysicsManager mPhysicsManager;
    EventLoop mEventLoop;

    Resource mAsteroidTexture;
    Resource mShipTexture;
    Resource mStarTexture;

    Asteroid mAsteroids;
    Ship mShip;
    StarField mStarField;
    SpriteBatch mSpriteBatch;
protected:
    status onActivate();
    void onDeactivate();
    status onStep();
    void onStart();

    void onResume() {};
    void onPause() {};
    void onStop() {};
    void onDestroy() {};
    void onSaveInstanceState(void** pData, size_t* pSize) {};
    void onConfigurationChanged() {};
    void onLowMemory() {};
    void onCreateWindow() {};
    void onDestroyWindow() {};
    void onGainFocus() {};
    void onLostFocus() {};

};

#endif //HELLOWORLDC_DROIDBLASTER_H
