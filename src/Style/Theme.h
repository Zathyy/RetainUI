#pragma once

#include "Core/Core.h"
#include "Math/Color.h"

namespace rui {

    struct RUI_API Theme
    {
        Color BackgroundColor;
        Color TextColor;
        Color TextShadowColor;
        Color ShadowColor;
        Color BorderColor;
        Color BorderShadowColor;
    };
}