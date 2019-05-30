//
// Created by yanny on 27/5/2019.
//

#ifndef HELLOWORLDC2_CMAKE_H
#define HELLOWORLDC2_CMAKE_H


/*
 *
 *
 *
 *
 cmake_minimum_required(VERSION 3.6.0)


set ( png_src_DIR ${ANDROID_NDK}/sources/libpng )
set ( png_build_DIR ${ANDROID_NDK}/sources/libpng/outputs )
file(MAKE_DIRECTORY ${png_build_DIR})
file(GLOB png_SOURCES "${png_src_DIR}/*.c")
add_subdirectory( # Specifies the directory of the CMakeLists.txt file.
        ${png_src_DIR}
         ##Specifies the directory for the build outputs.
        ${png_build_DIR})

#add_library( libpng STATIC IMPORTED )
add_library( # Sets the name of the library.
        libpng
        # Sets the library as a shared library.
        STATIC
        # Provides a relative path to your source file(s).
        # Associated headers in the same location as their source
        # file are automatically
        #included.
        ${png_SOURCES})
set_target_properties( libpng PROPERTIES IMPORTED_LOCATION ${png_build_DIR}/libpng.so )
include_directories( ${png_SOURCES} )


#set(png_src_dir C:/sdk/ndk-bundle/sources/libpng)
#set(PNG_STATIC ON)

#add_subdirectory(${png_src_dir} ${png_src_dir}/build)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++14")
#add_library(libpng STATIC IMPORTED)
#set_target_properties(libpng PROPERTIES IMPORTED_LOCATION ${png_src_dir}/obj/local/${ANDROID_ABI}/libpng.a)

add_library(native_app_glue STATIC
        ${ANDROID_NDK}/sources/android/native_app_glue/android_native_app_glue.c)
target_include_directories(native_app_glue PUBLIC
        ${ANDROID_NDK}/sources/android/native_app_glue

        ${png_src_DIR}
        )

find_library(log-lib
        log

        )

set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -u ANativeActivity_onCreate")
add_library(

        helloworld-c SHARED
        src/main/cpp/Main.cpp
        src/main/cpp/helloworld-c.cpp
        src/main/cpp/Log.cpp
        src/main/cpp/EventLoop.cpp
        src/main/cpp/DroidBlaster.cpp
        src/main/cpp/Ship.cpp
        src/main/cpp/GraphicsManager.cpp
        src/main/cpp/TimeManager.cpp
        src/main/cpp/PhysicsManager.cpp
        src/main/cpp/Asteroid.cpp
        src/main/cpp/Resource.cpp




        )




#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O3 -std=c99")

target_link_libraries(helloworld-c
        android
        native_app_glue
        ${log-lib}
        EGL
        GLESv2
        libpng
        z



        )
 * */
#endif //HELLOWORLDC2_CMAKE_H
