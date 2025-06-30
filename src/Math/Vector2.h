#pragma once

#include "Math.h"
#include "Point.h"
#include "Core/Core.h"

namespace rui {

    struct RUI_API Vector2
    {
        union
        {
            struct
            {
                float X;
                float Y;
            };

            float Raw[2];
        };

        Vector2() = default;

        explicit Vector2(const float xy)
            : X(xy),
              Y(xy)
        {
        }

        explicit Vector2(const Point& point)
            : X(static_cast<float>(point.X)),
              Y(static_cast<float>(point.Y))
        {
        }

        Vector2(const float& x, const float& y)
            : X(x),
              Y(y)
        {
        }

        Vector2(const Vector2& other)
            : X(other.X),
              Y(other.Y)
        {
        }

        NODISCARD Point ToPoint() const
        {
            return {static_cast<int32>(X), static_cast<int32>(Y)};
        }

        static bool Equals(const Vector2& first, const Vector2& second)
        {
            if (!math::ArefloatsEqual(first.X, second.X)) return false;
            if (!math::ArefloatsEqual(first.Y, second.Y)) return false;
            return true;
        }

        bool operator==(const Vector2& other) const
        {
            return Equals(*this, other);
        }

        bool operator!=(const Vector2& other) const
        {
            return !Equals(*this, other);
        }

        Vector2 operator+(const Vector2& v) const
        {
            Vector2 temp = *this;
            temp.X += v.X;
            temp.Y += v.Y;
            return temp;
        }

        Vector2 operator-(const Vector2 & rh) const
        {
            Vector2 temp = *this;
            temp.X -= rh.X;
            temp.Y -= rh.Y;
            return temp;
        }

        Vector2 operator*(const float x) const
        {
            Vector2 temp = *this;
            temp.X *= x;
            temp.Y *= x;
            return temp;
        }
    };
}
