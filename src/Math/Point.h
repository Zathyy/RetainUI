#pragma once

#include "Core/Core.h"

namespace rui
{
	struct RUI_API Point
	{
		Point()
		{
			X = 0;
			Y = 0;
		}
		Point(const Point& value)
		{
			X = value.X;
			Y = value.Y;
		}

		int X;
		int Y;
	};
}