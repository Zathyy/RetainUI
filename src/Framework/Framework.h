#pragma once

#include <functional>
#include "PlatformWindow.h"
#include "PlatformWindowHandle.h"
#include "Core/Core.h"

namespace rui {

    class RUI_API FrameworkCallbacks
    {
    public:
        std::function<void()> OnCreateWindow;
        std::function<void()> OnDestroyWindow;
        std::function<void()> OnResize;
    };

    struct RUI_API FrameworkCreateInfo
    {
        FrameworkCallbacks callbacks;

    };

    class RUI_API Framework
    {
    public:
        explicit Framework(FrameworkCreateInfo info);
        ~Framework();

        void Update();

        void* GetNativeWindowFromHandle(PlatformWindowHandle handle);

    private:
        FrameworkCreateInfo m_CreateInfo;

        std::vector<Ref<PlatformWindow>> m_PlatformWindows;
    };

}