#include "Framework.h"
#include <utility>

namespace rui {

    Framework::Framework(FrameworkCreateInfo info)
        : m_CreateInfo(std::move(info))
    {

    }

    Framework::~Framework()
    {

    }
} // rui