#pragma once

#include <span>
#include <vector>
#include "PlatformWindowHandle.h"
#include "Vertex.h"

namespace rui {

    struct RUI_API DrawData
    {
        PlatformWindowHandle windowHandle;
        std::vector<uint32> indexBuffer;
        std::vector<Vertex> vertexBuffer;
    };

    using DrawList = std::span<DrawData>;

}