#pragma once

#include <memory>
#include <vector>
#include "Math/Rect.h"

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

        void SetParent(Ref<Widget> parent);
        void SetRect(const Rect& rect);

    public:

        FORCE_INLINE Widget* GetParent() const
        {
            return m_Parent.get();
        }

        FORCE_INLINE Rect GetRect() const
        {
            return m_Rect;
        }

    protected:
        Ref<Widget> m_Parent = nullptr;
        Rect m_Rect;
    };

}