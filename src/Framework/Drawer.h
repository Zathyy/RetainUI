#pragma once

#include "DrawData.h"
#include "Core/Core.h"
#include "Math/Rect.h"

namespace rui {

    class RUI_API Drawer
    {
    public:

        static void DrawRectangle(DrawData& data, const Rect& rect);
    };

}
