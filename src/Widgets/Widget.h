#pragma once

#include <memory>
#include <vector>
#include "Math/Rect.h"
#include "Math/Vector2.h"

namespace rui {

    /// <summary>
    /// Widget class. \n
    /// It's the underlying type for every ui element.
    /// </summary>
    class RUI_API Widget
    {
    public:
        virtual ~Widget() {}

        virtual bool OnMouseMove(const Point& point);
        virtual bool OnMouseDown(const Point& point);
        virtual bool OnMouseUp(const Point& point);
        virtual bool OnMouseLeave();
        virtual bool OnMouseEnter();

        void SetParent(const Ref<Widget> &parent);
        void SetRect(const Rect& rect);

        virtual Vector2 ComputeDesiredSize();

        virtual void Layout(const Rect& availableRect);

    public:

        FORCE_INLINE Widget* GetParent() const
        {
            return m_Parent.lock().get();
        }

        FORCE_INLINE Rect GetRect() const
        {
            return m_Rect;
        }

    protected:
        std::weak_ptr<Widget> m_Parent;
        Rect m_Rect;

        float m_Margin = 0.0f;
        float m_Padding = 0.0f;

        int32 m_MinWidth = 0;
        int32 m_MaxWidth = 0;

        int32 m_MinHeight = 0;
        int32 m_MaxHeight = 0;
    };

}
