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

        NODISCARD int32 X() const { return Offset.X; }
        NODISCARD int32 Y() const { return Offset.Y; }
        NODISCARD int32 Width() const { return Extent.X; }
        NODISCARD int32 Height() const { return Extent.Y; }

        NODISCARD Point Position() const { return Offset; }
        NODISCARD Point Size() const { return Extent; }

        NODISCARD bool Contains(const Point& point) const
        {
            return point.X >= Offset.X && point.X <= Offset.X + Extent.X &&
                   point.Y >= Offset.Y && point.Y <= Offset.Y + Extent.Y;
        }

        NODISCARD Rect Inflate(const int32 amount) const
        {
            return {
                { Extent.X + amount * 2, Extent.Y + amount * 2 },
                { Offset.X - amount, Offset.Y - amount }
            };
        }

        NODISCARD Rect Intersect(const Rect& other) const
        {
            int32 x1 = math::Max(Offset.X, other.Offset.X);
            int32 y1 = math::Max(Offset.Y, other.Offset.Y);
            int32 x2 = math::Min(Offset.X + Extent.X, other.Offset.X + other.Extent.X);
            int32 y2 = math::Min(Offset.Y + Extent.Y, other.Offset.Y + other.Extent.Y);

            if (x2 <= x1 || y2 <= y1)
                return Rect();

            return Rect({ x2 - x1, y2 - y1 }, { x1, y1 });
        }
    };
}

