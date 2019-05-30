//
// Created by yanny on 25/5/2019.
//

#include "EventLoop.h"
#include "Log.h"

EventLoop::EventLoop(android_app* pApplication, ActivityHandler& pActivityHandler):
        mApplication(pApplication),
        mEnabled(false), mQuit(false),
        mActivityHandler(pActivityHandler)
{

    mApplication->userData = this;
    mApplication->onAppCmd = callback_appEvent;

}
void EventLoop::run() {
    int32_t result; int32_t events;
    android_poll_source* source;
    // Makes sure native glue is not stripped by the linker.
    //app_dummy();
    Log::info("Starting event loop de Yanny");
    while (true) {
        // Event processing loop.
        while ((result = ALooper_pollAll(mEnabled ? 0 : -1, nullptr, &events, (void**) &source)) >= 0) {
            // An event has to be processed.
            if (source != nullptr) {
                Log::info("Processing an event");
                source->process(mApplication, source);
            }
            // Application is getting destroyed.
            if (mApplication->destroyRequested) {
                Log::info("Exiting event loop");
                return;
            }
        }
        // Steps the application.
        if ((mEnabled) && (!mQuit)) {
            if (mActivityHandler.onStep() != STATUS_OK) {
                mQuit = true;
                ANativeActivity_finish(mApplication->activity);
            }
        }

    }
}

void EventLoop::activate() {
    // Enables activity only if a window is available.
    if ((!mEnabled) && (mApplication->window != nullptr)) {
        mQuit = false; mEnabled = true;
        if (mActivityHandler.onActivate() != STATUS_OK) {
            goto ERROR;
        }
    }
    return;
    ERROR:
        mQuit = true;
        deactivate();
        ANativeActivity_finish(mApplication->activity);
}
void EventLoop::deactivate() {
    if (mEnabled) {
        mActivityHandler.onDeactivate();
        mEnabled = false;
    }

}


void EventLoop::processAppEvent(int32_t pCommand) {
    switch (pCommand) {
        case APP_CMD_CONFIG_CHANGED:

            mActivityHandler.onConfigurationChanged();
            break;
        case APP_CMD_INIT_WINDOW:
            mActivityHandler.onCreateWindow();
            break;
        case APP_CMD_DESTROY:
            mActivityHandler.onDestroy();
            break;
        case APP_CMD_GAINED_FOCUS:
            activate();
            mActivityHandler.onGainFocus();
            break;
        case APP_CMD_LOST_FOCUS:
            mActivityHandler.onLostFocus();
            deactivate();
            break;
        case APP_CMD_LOW_MEMORY:
            mActivityHandler.onLowMemory();
            break;
        case APP_CMD_PAUSE:
            mActivityHandler.onPause();
            deactivate();
            break;
        case APP_CMD_RESUME:
            mActivityHandler.onResume();
            break;
        case APP_CMD_SAVE_STATE:
            mActivityHandler.onSaveInstanceState(
                    &mApplication->savedState, &mApplication->savedStateSize);
            break;
        case APP_CMD_START:
            mActivityHandler.onStart();
            break;
        case APP_CMD_STOP:
            mActivityHandler.onStop();
            break;
        case APP_CMD_TERM_WINDOW:
            mActivityHandler.onDestroyWindow();
            deactivate();
            break;
        default:
            break;
    }
}

    void EventLoop::callback_appEvent(android_app* pApplication, int32_t pCommand) {
        EventLoop& eventLoop = *(EventLoop*) pApplication->userData;
        eventLoop.processAppEvent(pCommand);
    }