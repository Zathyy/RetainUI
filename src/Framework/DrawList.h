#pragma once

#include <vector>
#include "PlatformWindowHandle.h"
#include "Vertex.h"

namespace rui {

    struct RUI_API DrawList
    {
        PlatformWindowHandle windowHandle;
        std::vector<uint32> indexBuffer;
        std::vector<Vertex> vertexBuffer;
    };

}