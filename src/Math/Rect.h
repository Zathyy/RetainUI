#pragma once

#include "Vector2.h"
#include "Core/Core.h"

namespace rui {

    struct RUI_API Rect
    {
        Vector2 Extent { 0 };
        Vector2 Offset { 0 };

        Rect() = default;

        Rect(const Vector2& extent, const Vector2& offset)
            : Extent(extent), Offset(offset)
        {
        }

        Rect(const Vector2& extent)
            : Extent(extent)
        {
        }

        float X() const { return Offset.X; }
        float Y() const { return Offset.Y; }
        float Width() const { return Extent.X; }
        float Height() const { return Extent.Y; }

        Vector2 Position() const { return Offset; }
        Vector2 Size() const { return Extent; }


        bool Contains(const Vector2& point) const
        {
            return point.X >= Offset.X && point.X <= Offset.X + Extent.X &&
                   point.Y >= Offset.Y && point.Y <= Offset.Y + Extent.Y;
        }

        Rect Inflate(const float amount) const
        {
            return {
                { Extent.X + amount * 2.0f, Extent.Y + amount * 2.0f },
                { Offset.X - amount, Offset.Y - amount }
            };
        }

        Rect Intersect(const Rect& other) const
        {
            float x1 = math::Max(Offset.X, other.Offset.X);
            float y1 = math::Max(Offset.Y, other.Offset.Y);
            float x2 = math::Min(Offset.X + Extent.X, other.Offset.X + other.Extent.X);
            float y2 = math::Min(Offset.Y + Extent.Y, other.Offset.Y + other.Extent.Y);

            if (x2 <= x1 || y2 <= y1)
                return Rect();

            return Rect({ x2 - x1, y2 - y1 }, { x1, y1 });
        }
    };
}

