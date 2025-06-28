#pragma once

#include <cmath>
#include <numbers>
#include "Core/Core.h"
#include "Core/Primitives.h"

namespace rui::math {

    constexpr float PI = std::numbers::pi_v<float>;
    constexpr float HalfPI = PI * 0.5f;

    constexpr float RadiansToDegrees = (180.0f / PI);
    constexpr float DegreesToRadians = PI / 180.0f;

    constexpr float ZeroTolerance = 1e-6f;

    FORCE_INLINE float DegToRad(const float Deg)
    {
        return Deg * Deg2Rad;
    }

    FORCE_INLINE float RadToDeg(const float Rad)
    {
        return Rad * Rad2Deg;
    }

    template<typename A>
    A Max(const A first, const A second)
    {
        static_assert(std::is_arithmetic_v<A>, "T must be arithmetic type");
        return first > second ? first : second;
    }

    template<typename A>
    A Min(const A first, const A second)
    {
        static_assert(std::is_arithmetic_v<A>, "T must be arithmetic type");
        return first < second ? first : second;
    }

    inline float Abs(const float value)
    {
        return std::fabs(value);
    }

    inline int32 Abs(const int32 value)
    {
        return value < 0 ? -value : value;
    }

    inline int64 Abs(const int64 value)
    {
        return value < 0 ? -value : value;
    }

    inline float Sqrt(const float value)
    {
        return sqrtf(value);
    }

    inline float Tan(const float value)
    {
        return tanf(value);
    }

    inline float Asin(const float value)
    {
        return asinf(value);
    }

    inline float Sin(const float value)
    {
        return sinf(value);
    }

    inline float Cos(const float value)
    {
        return cosf(value);
    }

    inline float Atan2(const float y, const float x)
    {
        return atan2f(y, x);
    }

    template<class T>
    T Clamp(const T value, const T min, const T max)
    {

        static_assert(std::is_arithmetic_v<T>, "T must be arithmetic type");
        return value < min ? min : value < max ? value : max;
    }

    inline bool ArefloatsEqual(const float a, const float b)
    {
        return Abs(a - b) <= ZeroTolerance;
    }
}