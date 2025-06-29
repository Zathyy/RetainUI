#pragma once

#include "Core/Core.h"
#include "Math.h"
#include "Point.h"

namespace rui {

    struct RUI_API Rect
    {
        Point Extent;
        Point Offset;

        Rect() = default;

        Rect(const Point& extent, const Point& offset)
            : Extent(extent), Offset(offset)
        {
        }

        explicit Rect(const Point& extent)
            : Extent(extent)
        {
        }

        NODISCARD float X() const { return Offset.X; }
        NODISCARD float Y() const { return Offset.Y; }
        NODISCARD float Width() const { return Extent.X; }
        NODISCARD float Height() const { return Extent.Y; }

        NODISCARD Point Position() const { return Offset; }
        NODISCARD Point Size() const { return Extent; }

        NODISCARD bool Contains(const Point& point) const
        {
            return point.X >= Offset.X && point.X <= Offset.X + Extent.X &&
                   point.Y >= Offset.Y && point.Y <= Offset.Y + Extent.Y;
        }

        NODISCARD Rect Inflate(const float amount) const
        {
            return {
                { Extent.X + amount * 2.0f, Extent.Y + amount * 2.0f },
                { Offset.X - amount, Offset.Y - amount }
            };
        }

        NODISCARD Rect Intersect(const Rect& other) const
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

