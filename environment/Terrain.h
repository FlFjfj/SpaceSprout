//
// Created by opot on 01.04.18.
//

#ifndef GLUTGL_TERRAIN_H
#define GLUTGL_TERRAIN_H

#include "../GlUtils/Texture.h"
#include "../GlUtils/Shader.h"
#include "../GlUtils/SpriteBatch.h"
#include "../GlUtils/OrthographicCamera.h"

using namespace fjfj;

class StaticObject {
public:
    Texture *tex;
    float x, y;

    explicit StaticObject(Texture *tex, float x, float y);

    virtual void update(float delta) = 0;

    virtual void draw(SpriteBatch *batch, OrthographicCamera *cam, float elapsed) = 0;

    virtual int getType() = 0;
};

class Terrain : public StaticObject {
    float deltaTime;
    float deltaSpeed;
public:
    explicit Terrain(Texture *tex, float x, float y, double (*gen)());

    void update(float delta) override;

    void draw(SpriteBatch *batch, OrthographicCamera *cam, float elapsed) override;

    int getType() override { return 0; };

    static Shader *TerrainShader;
    static GLint u_ModelTrans;
    static GLint u_ProjTrans;
    static GLint u_FrameCount;
    static GLint u_FrameTime;
    static GLint u_Time;

    const int FRAMECOUNT = 3;
    const float FRAMELENGTH = 0.7;
};

class Exit : public StaticObject {
    float deltaTime;
    float deltaSpeed;
public:
    explicit Exit(Texture *tex, float x, float y, double (*gen)());

    void update(float delta) override;

    void draw(SpriteBatch *batch, OrthographicCamera *cam, float elapsed) override;

    int getType() override { return 1; };

    static Shader *exitShader;
    static GLint u_ModelTrans;
    static GLint u_ProjTrans;
    static GLint u_FrameCount;
    static GLint u_FrameTime;
    static GLint u_Time;

    const int FRAMECOUNT = 5;
    const float FRAMELENGTH = 0.1;
};


#endif //GLUTGL_TERRAIN_H
