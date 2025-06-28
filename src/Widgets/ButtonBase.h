#pragma once

#include <functional>

#include "Widget.h"

namespace rui {

class ButtonBase : public Widget
{
public:

protected:

    std::function<void()> onClick;
    std::function<void()> onHover;
};

}
