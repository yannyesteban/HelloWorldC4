//
// Created by yanny on 25/5/2019.
//
#include <android_native_app_glue.h>
//#include <jni.h>
#include "Types.h"
#include "DroidBlaster.h"
#include "EventLoop.h"
#include "Log.h"




void android_main(android_app* pApplication) {
    //EventLoop(pApplication).run();
    DroidBlaster(pApplication).run();
}