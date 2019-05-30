//
// Created by yanny on 25/5/2019.
//

#include "Log.h"

#include <stdarg.h>
#include <android/log.h>

void Log::info(const char* pMessage, ...) {
    va_list varArgs;
    va_start(varArgs, pMessage);
    __android_log_vprint(ANDROID_LOG_INFO, "PACKT", pMessage, varArgs);
    __android_log_print(ANDROID_LOG_INFO, "PACKT", "\n");
    va_end(varArgs);
}

void Log::error(const char* pMessage, ...) {
    va_list varArgs;
    va_start(varArgs, pMessage);
    __android_log_vprint(ANDROID_LOG_ERROR, "PACKT", pMessage, varArgs);
    __android_log_print(ANDROID_LOG_ERROR, "PACKT", "\n");
    va_end(varArgs);
}

void Log::warn(const char* pMessage, ...) {
    va_list varArgs;
    va_start(varArgs, pMessage);
    __android_log_vprint(ANDROID_LOG_WARN, "PACKT", pMessage, varArgs);
    __android_log_print(ANDROID_LOG_WARN, "PACKT", "\n");
    va_end(varArgs);
}

void Log::debug(const char* pMessage, ...) {
    va_list varArgs;
    va_start(varArgs, pMessage);
    __android_log_vprint(ANDROID_LOG_DEBUG, "PACKT", pMessage, varArgs);
    __android_log_print(ANDROID_LOG_DEBUG, "PACKT", "\n");
    va_end(varArgs);
}