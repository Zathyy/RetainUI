#include "Widget.h"
#include "Math/Vector2.h"
#include "Math/Math.h"

namespace rui {

    bool Widget::OnMouseMove(const Point &point)
    {
        return false;
    }

    bool Widget::OnMouseDown(const Point &point)
    {
        return false;
    }

    bool Widget::OnMouseUp(const Point &point)
    {
        return false;
    }

    bool Widget::OnMouseLeave()
    {
        return false;
    }

    bool Widget::OnMouseEnter()
    {
        return false;
    }

    void Widget::SetParent(const Ref<Widget>& parent)
    {
        m_Parent = parent;
    }

    void Widget::SetRect(const Rect &rect)
    {
        m_Rect = rect;
    }

    Vector2 Widget::ComputeDesiredSize()
    {
        return {static_cast<float>(m_Rect.Width), static_cast<float>(m_Rect.Height)};
    }

    void Widget::Layout(const Rect& availableRect)
    {
        const Vector2 desiredSize = ComputeDesiredSize(); // text size, image size, min/max constraints

        // Clamp desired size to availableRect
        Vector2 finalSize{};
        finalSize.X = math::Min(desiredSize.X + m_Padding * 2, availableRect.Width);
        finalSize.Y = math::Min(desiredSize.Y + m_Padding * 2, availableRect.Height);

        const Vector2 finalPosition = Vector2(availableRect.Position()) + Vector2(m_Margin, m_Margin);

        m_Rect = Rect(finalPosition.ToPoint(),  finalSize.ToPoint());
    }
}
