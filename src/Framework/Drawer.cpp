
#include "Drawer.h"

namespace rui {

    void Drawer::DrawRectangle(DrawData& data, const Rect& rect)
    {
        Vector2 topLeft = Vector2(rect.Position());
        Vector2 topRight = topLeft + Vector2(static_cast<float>(rect.Width), 0.0f);
        Vector2 bottomLeft = topLeft + Vector2(0.0f, static_cast<float>(rect.Height));
        Vector2 bottomRight = topLeft + Vector2(static_cast<float>(rect.Width), static_cast<float>(rect.Height));

        Vertex v1 = Vertex(topLeft,     {0.0f, 1.0f});
        Vertex v2 = Vertex(topRight,    {1.0f, 1.0f});
        Vertex v3 = Vertex(bottomRight, {1.0f, 0.0f});
        Vertex v4 = Vertex(bottomLeft,  {0.0f, 0.0f});

        data.vertexBuffer.push_back(v1);
        data.vertexBuffer.push_back(v2);
        data.vertexBuffer.push_back(v3);
        data.vertexBuffer.push_back(v4);

        uint32 baseIndex = static_cast<uint32_t>(data.vertexBuffer.size()) - 4;

        data.indexBuffer.push_back(baseIndex + 0);
        data.indexBuffer.push_back(baseIndex + 1);
        data.indexBuffer.push_back(baseIndex + 2);

        data.indexBuffer.push_back(baseIndex + 0);
        data.indexBuffer.push_back(baseIndex + 2);
        data.indexBuffer.push_back(baseIndex + 3);
    }


}
