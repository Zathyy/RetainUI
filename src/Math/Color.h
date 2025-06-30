#pragma once

#include "Core/Core.h"

namespace rui {

    struct RUI_API Color
    {
        float R;
        float G;
        float B;
        float A;

        static Color Red;
        static Color Green;
        static Color Blue;
        static Color Black;
        static Color White;

        Color(const float r, const float g, const float b, const float a = 1.0f)
        {
            R = r;
            G = g;
            B = b;
            A = a;
        }

        [[nodiscard]] const float* ValuePtr() const
        {
            return &R;
        }
    };
}
