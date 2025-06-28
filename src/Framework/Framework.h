#pragma once

#include <functional>
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


    private:
        FrameworkCreateInfo m_CreateInfo;


    };

}
