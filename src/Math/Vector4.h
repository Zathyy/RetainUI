#pragma once

#include "Math.h"
#include "Core/Core.h"

namespace rui {

    struct RUI_API Vector4
    {
    private:
        friend std::size_t hash_value(const Vector4 &obj)
        {
            std::size_t seed = 0x25A5D2D1;
            seed ^= (seed << 6) + (seed >> 2) + 0x3A734906 + static_cast<std::size_t>(obj.X);
            seed ^= (seed << 6) + (seed >> 2) + 0x6DE9118D + static_cast<std::size_t>(obj.Y);
            seed ^= (seed << 6) + (seed >> 2) + 0x631B2F2D + static_cast<std::size_t>(obj.Z);
            seed ^= (seed << 6) + (seed >> 2) + 0x532AE062 + static_cast<std::size_t>(obj.W);
            return seed;
        }

    public:

        float X;
        float Y;
        float Z;
        float W;

        Vector4() = default;

        explicit Vector4(const float xyzw)
        {
            X = xyzw;
            Y = xyzw;
            Z = xyzw;
            W = xyzw;
        }

        NODISCARD const float* ValuePtr() const
        {
            return &X;
        }

        static bool Equals(const Vector4 &lhs, const Vector4 &rhs)
        {
            if (!math::ArefloatsEqual(lhs.X, rhs.X)) return false;
            if (!math::ArefloatsEqual(lhs.Y, rhs.Y)) return false;
            if (!math::ArefloatsEqual(lhs.Z, rhs.Z)) return false;
            if (!math::ArefloatsEqual(lhs.W, rhs.W)) return false;
            return true;
        }

        bool operator==(const Vector4& other) const
        {
            return Equals(*this, other);
        }

        bool operator!=(const Vector4& other) const
        {
            return !Equals(*this, other);
        }

        Vector4 operator+(const Vector4& second) const
        {
            Vector4 result{};
            result.X = this->X + second.X;
            result.Y = this->Y + second.Y;
            result.Z = this->Z + second.Z;
            result.W = this->W + second.W;
            return result;
        }
    };

}