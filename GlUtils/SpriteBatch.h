//
// Created by opot on 20.04.17.
//

#ifndef GLUTGL_SPRITEBATCH_H
#define GLUTGL_SPRITEBATCH_H

#include "Texture.h"
#include "Mesh.h"

namespace fjfj {

    class SpriteBatch {

        Mesh* square;

    public:
        SpriteBatch();
        void draw(const Texture& tex, GLint model_location, float x, float y, float width, float height);
        void draw(const Texture& tex, GLint model_location, float x, float y, float width, float height, float angle);

    };

}

#endif //GLUTGL_SPRITEBATCH_H
