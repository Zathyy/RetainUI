#pragma once

#include <functional>

#include "Widget.h"

namespace rui {

    class RUI_API ButtonBase : public Widget
    {
    public:



    protected:

        std::function<void()> onClick;
        std::function<void()> onHover;
    };

}
