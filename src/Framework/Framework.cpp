#include "Framework.h"

#include <assert.h>
#include <utility>

namespace rui {

    Framework::Framework(FrameworkCreateInfo info)
        : m_CreateInfo(std::move(info))
    {

    }

    Framework::~Framework()
    {
    }

    void Framework::Update()
    {
        for (const auto& window : m_PlatformWindows)
        {
            window->Update();
        }
    }

    void* Framework::GetNativeWindowFromHandle(const PlatformWindowHandle handle) const
    {
        for (const auto& window : m_PlatformWindows)
        {
            if (window->GetHandle() == handle)
            {
                return window->GetNativeWindow();
            }
        }

        return nullptr;
    }
}
