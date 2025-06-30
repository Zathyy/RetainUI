#pragma once

#include "DrawData.h"
#include "Core/Core.h"
#include "Math/Vector2.h"
#include "Widgets/Widget.h"

namespace rui {

    struct RUI_API InteractableWindowCreateFlags
    {
        Rect rect;
    };

    class RUI_API InteractableWindow
    {
    public:
        InteractableWindow(InteractableWindowCreateFlags flags);
        ~InteractableWindow();

    private:
        NODISCARD Ref<Widget> GetRootWidget() const;

    private:
        InteractableWindowCreateFlags m_Flags;

        Rect m_Rect;
        std::vector<Ref<Widget>> m_Widgets;
    };

}
