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

        }
    }

    void* Framework::GetNativeWindowFromHandle(PlatformWindowHandle handle)
    {
        assert(false);
        return nullptr;
    }
}
