#pragma once

#include "Core/Core.h"

namespace rui
{
	struct RUI_API Point
	{
		int X;
		int Y;

		Point()
		{
			X = 0;
			Y = 0;
		}
		Point(int Value)
		{
			this->X = Value;
			this->Y = Value;
		}
		Point(int X, int Y)
		{
			this->X = X;
			this->Y = Y;
		}
		Point(const Point& value)
		{
			X = value.X;
			Y = value.Y;
		}
		Point& operator=(const Point& value)
		{
			X = value.X;
			Y = value.Y;
			return *this;
		}

		Point operator+(const Point& value)
		{
			Point point;
			point.X = X + value.X;
			point.Y = Y + value.Y;
			return point;
		}
		Point operator-(const Point& value)
		{
			Point point;
			point.X = X - value.X;
			point.Y = Y - value.Y;
			return point;
		}
		Point operator*(const Point& value)
		{
			Point point;
			point.X = X * value.X;
			point.Y = Y * value.Y;
			return point;
		}
		Point operator/(const Point& value)
		{
			Point point;
			point.X = X / value.X;
			point.Y = Y / value.Y;
			return point;
		}

		Point& operator+=(const Point& value)
		{
			X += value.X;
			Y += value.Y;
			return *this;
		}
		Point& operator-=(const Point& value)
		{
			X -= value.X;
			Y -= value.Y;
			return *this;
		}
		Point& operator*=(const Point& value)
		{
			X *= value.X;
			Y *= value.Y;
			return *this;
		}
		Point& operator/=(const Point& value)
		{
			X /= value.X;
			Y /= value.Y;
			return *this;
		}
	};
}