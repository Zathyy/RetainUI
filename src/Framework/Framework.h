#pragma once

#include <functional>
#include "PlatformWindow.h"
#include "PlatformWindowHandle.h"
#include "Core/Core.h"

namespace rui {

    class RUI_API FrameworkCallbacks
    {
    public:
        /// <summary>
        /// Called then RetainUI Wants to create a new window
        /// </summary>
        std::function<void(PlatformWindow&)> OnCreateWindow;

        /// <summary>
        /// Called when RetainUI wants to destroy a certain window
        /// </summary>
        std::function<void(PlatformWindow&)> OnDestroyWindow;

        /// <summary>
        /// Called when RetainUI wants to resize a particular window
        /// </summary>
        std::function<void(PlatformWindow&)> OnResize;
    };

    struct RUI_API FrameworkCreateInfo
    {
        FrameworkCallbacks callbacks;

    };

    /// <summary>
    /// Framework is the Manager in RetainUI.
    /// It manages states, windows
    /// </summary>
    class RUI_API Framework
    {
    public:
        explicit Framework(FrameworkCreateInfo info);
        ~Framework();

        void Update();

        /// <summary>
        /// Gets the Native window as a void*
        /// </summary>
        NODISCARD void* GetNativeWindowFromHandle(PlatformWindowHandle handle) const;

    private:
        FrameworkCreateInfo m_CreateInfo;

        std::vector<Ref<PlatformWindow>> m_PlatformWindows;
    };

}