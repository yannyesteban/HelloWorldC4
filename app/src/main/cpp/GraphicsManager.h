//
// Created by yanny on 25/5/2019.
//

#ifndef HELLOWORLDC_GRAPHICSMANAGER_H
#define HELLOWORLDC_GRAPHICSMANAGER_H

#include "Resource.h"

#include "Types.h"
#include <android_native_app_glue.h>
#include <GLES2/gl2.h>
#include <EGL/egl.h>


struct TextureProperties {
    Resource* textureResource;
    GLuint texture;
    int32_t width;
    int32_t height;
};

struct GraphicsElement {
    GraphicsElement(int32_t pWidth, int32_t pHeight):
            location(),
            width(pWidth), height(pHeight) {
    }
    Location location;
    int32_t width; int32_t height;
};
class GraphicsComponent {
public:
    virtual status load() = 0;
    virtual void draw() = 0;
};

class GraphicsManager {
public:
    GraphicsManager(android_app* pApplication);
    ~GraphicsManager();
    int32_t getRenderWidth() { return mRenderWidth; }
    int32_t getRenderHeight() { return mRenderHeight; }
    //GraphicsElement* registerElement(int32_t pHeight, int32_t pWidth);

    GLfloat* getProjectionMatrix() { return mProjectionMatrix[0]; }
    void registerComponent(GraphicsComponent* pComponent);


    status start();
    void stop();
    status update();

    TextureProperties* loadTexture(Resource& pResource);

    GLuint loadShader(const char* pVertexShader, const char* pFragmentShader);
private:
    android_app* mApplication;

    int32_t mRenderWidth;
    int32_t mRenderHeight;

    EGLDisplay mDisplay; EGLSurface mSurface; EGLContext mContext;
    GLfloat mProjectionMatrix[4][4];


    TextureProperties mTextures[32]; int32_t mTextureCount;
    //GraphicsElement* mElements[1024];
    GLuint mShaders[32]; int32_t mShaderCount;

    //int32_t mElementCount;

    GraphicsComponent* mComponents[32]; int32_t mComponentCount;
};



#endif //HELLOWORLDC_GRAPHICSMANAGER_H
