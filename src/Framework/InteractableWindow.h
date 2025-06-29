#pragma once

#include "Core/Core.h"
#include "Math/Vector2.h"
#include "Widgets/Widget.h"

namespace rui {

    struct RUI_API InteractableWindowCreateFlags
    {
        Vector2 Positon;

    };

    class RUI_API InteractableWindow
    {
    public:


    private:
        NODISCARD Ref<Widget> GetRootWidget() const;

    private:

        std::vector<Ref<Widget>> m_Widgets;
    };

}
