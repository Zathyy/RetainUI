#pragma once

#include <vector>

#include "DrawList.h"
#include "InteractableWindow.h"
#include "Core/Core.h"
#include "Core/Primitives.h"

namespace rui {

    struct RUI_API PlatformWindowCreateInfo
    {
        uint32 width;
        uint32 height;
    };

    class RUI_API PlatformWindow
    {
    public:
        PlatformWindow();
        ~PlatformWindow();

    private:
        std::vector<Ref<InteractableWindow>> m_InteractableWindows;
        DrawList m_DrawList;
    };

}
