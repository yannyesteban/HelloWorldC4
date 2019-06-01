//
// Created by yanny on 31/5/2019.
//

#ifndef HELLOWORLDC2_STARFIELD_H
#define HELLOWORLDC2_STARFIELD_H
#include "GraphicsManager.h"
#include "TimeManager.h"
#include "Types.h"
#include <GLES2/gl2.h>

class StarField : public GraphicsComponent {
public:
    StarField(android_app* pApplication, TimeManager& pTimeManager,
              GraphicsManager& pGraphicsManager, int32_t pStarCount,
              Resource& pTextureResource);
    status load();
    void draw();
private:
    struct Vertex {
        GLfloat x, y, z;
    };
    TimeManager& mTimeManager;
    GraphicsManager& mGraphicsManager;
    int32_t mStarCount;
    Resource& mTextureResource;
    GLuint mVertexBuffer; GLuint mTexture; GLuint mShaderProgram;
    GLuint aPosition; GLuint uProjection;
    GLuint uTime; GLuint uHeight; GLuint uTexture;
};

#endif //HELLOWORLDC2_STARFIELD_H
