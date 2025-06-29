#pragma once

#include <vector>

#include "DrawData.h"
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

        NODISCARD PlatformWindowHandle GetHandle() const { return m_Handle; }
        NODISCARD void* GetNativeWindow() const { return m_NativeWindow; }



    private:
        std::vector<Ref<InteractableWindow>> m_InteractableWindows;
        DrawData m_DrawList;
        PlatformWindowHandle m_Handle;
        void* m_NativeWindow;
    };

}
