//
// Created by yanny on 29/5/2019.
//

#ifndef HELLOWORLDC2_SPRITEBATCH_H
#define HELLOWORLDC2_SPRITEBATCH_H

#include "GraphicsManager.h"
#include "Sprite.h"
#include "TimeManager.h"
#include "Types.h"
#include <GLES2/gl2.h>
class SpriteBatch : public GraphicsComponent {
public:
    SpriteBatch(TimeManager& pTimeManager,
                GraphicsManager& pGraphicsManager);
    ~SpriteBatch();
    Sprite* registerSprite(Resource& pTextureResource,
                           int32_t pHeight, int32_t pWidth);
    status load();
    void draw();
private:
    TimeManager& mTimeManager;
    GraphicsManager& mGraphicsManager;
    Sprite* mSprites[1024]; int32_t mSpriteCount;
    Sprite::Vertex mVertices[1024]; int32_t mVertexCount;
    GLushort mIndexes[1024]; int32_t mIndexCount;
    GLuint mShaderProgram;
    GLuint aPosition; GLuint aTexture;
    GLuint uProjection; GLuint uTexture;
};
#endif //HELLOWORLDC2_SPRITEBATCH_H
