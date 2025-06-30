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
        void* nativeWindow;
    };

    class RUI_API PlatformWindow
    {
        friend class Framework;
    public:
        PlatformWindow();
        ~PlatformWindow();

        NODISCARD PlatformWindowHandle GetHandle() const { return m_Handle; }
        NODISCARD void* GetNativeWindow() const { return m_NativeWindow; }

    private:
        void Update();


    private:
        std::vector<Ref<InteractableWindow>> m_InteractableWindows;
        DrawData m_DrawData;
        PlatformWindowHandle m_Handle;
        void* m_NativeWindow;
    };

}
