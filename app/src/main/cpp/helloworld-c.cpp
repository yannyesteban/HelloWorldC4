//
// Created by yanny on 20/5/2019.
//

#include <EGL/egl.h>
#include <GLES/gl.h>


#include <android/sensor.h>
#include <android/log.h>


#include <android_native_app_glue.h>
#include <jni.h>

extern "C" {
void handle_cmd(android_app *pApp, int32_t cmd) {
}

void android_main1(struct android_app *pApp) {
    pApp->onAppCmd = handle_cmd;

    int events;
    android_poll_source *pSource;
    do {
        if (ALooper_pollAll(0, nullptr, &events, (void **) &pSource) >= 0) {
            if (pSource) {
                pSource->process(pApp, pSource);
            }
        }
    } while (!pApp->destroyRequested);
}
}