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
    protected:
        typedef Widget base;

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
            return m_Parent.lock().get();
        }

        FORCE_INLINE Rect GetRect() const
        {
            return m_Rect;
        }

    protected:
        std::weak_ptr<Widget> m_Parent;
        Rect m_Rect;

        int32 m_Width = 0;
        int32 m_Height = 0;

        int32 m_MinWidth = 0;
        int32 m_MaxWidth = 0;

        int32 m_MinHeight = 0;
        int32 m_MaxHeight = 0;
    };

}