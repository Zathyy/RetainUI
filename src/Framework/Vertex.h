#pragma once

#include "Math/Vector2.h"

namespace rui {

    struct Vertex
    {
        Vertex() = default;
        Vertex(const Vector2 &pos, const Vector2 &uv)
            : position(pos), uv(uv)
        {
        }

        Vector2 position;
        Vector2 uv;
    };
}

