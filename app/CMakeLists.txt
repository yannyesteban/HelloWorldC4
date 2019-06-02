cmake_minimum_required(VERSION 3.6.0)





add_library(native_app_glue STATIC ${ANDROID_NDK}/sources/android/native_app_glue/android_native_app_glue.c)
target_include_directories(native_app_glue PUBLIC
        ${ANDROID_NDK}/sources/android/native_app_glue

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
        src/main/cpp/Sprite.cpp
        src/main/cpp/SpriteBach.cpp
        src/main/cpp/StarField.cpp
        src/main/cpp/SoundManager.cpp



        )


# Sets lib_src_DIR to the path of the target CMake project.
set( lib_src_DIR ${ANDROID_NDK}/sources/libpng )



#file(GLOB png_SOURCES "${png_src_DIR}/*.c")
# Sets lib_build_DIR to the path of the desired output directory.
#set( lib_build_DIR ${ANDROID_NDK}/sources/libpng/${ANDROID_ABI}/outputs )
#file(MAKE_DIRECTORY ${lib_build_DIR})

# Adds the CMakeLists.txt file located in the specified directory
# as a build dependency.
#add_subdirectory( # Specifies the directory of the CMakeLists.txt file.
        #${lib_src_DIR}
        # Specifies the directory for the build outputs.
        #${lib_build_DIR} )

# Adds the output of the additional CMake build as a prebuilt static
# library and names it lib_gmath.
add_library( libpng STATIC IMPORTED )

set_target_properties( # Specifies the target library.
        libpng

        # Specifies the parameter you want to define.
        PROPERTIES IMPORTED_LOCATION

        # Provides the path to the library you want to import.
        ${lib_src_DIR}/obj/local/${ANDROID_ABI}/libpng.a )


include_directories( ${lib_src_DIR}/jni )



find_library(
        log-lib
        log

)

target_link_libraries(helloworld-c
        android
        native_app_glue
        ${log-lib}
        EGL
        GLESv2
        libpng
        z

        )