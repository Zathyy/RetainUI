#pragma once

#include <memory>
#include <vector>
#include "Math/Rect.h"

namespace rui {

    /// <summary>
    /// Widget class. \n
    /// Is the underlying type everything
    /// </summary>
    class RUI_API Widget
    {
    public:
        virtual ~Widget() {}

        bool OnMouseMove(int32 x, int32 y);
        bool OnMouseDown(int32 x, int32 y);
        bool OnMouseUp(int32 x, int32 y);
        bool OnMouseLeave();
        bool OnMouseEnter();

        void SetParent(Ref<Widget> parent);
        void SetRect(const Rect& rect);
        void ClearChildren();

    public:

        FORCE_INLINE bool HasChildren() const { return !m_Children.empty(); }
        FORCE_INLINE Widget* GetParent() const
        {
            return m_Parent.get();
        }
        FORCE_INLINE Rect GetRect() const {
            return m_Rect;
        }
        FORCE_INLINE const std::vector<Ref<Widget>>& GetChildren() const {
            return m_Children;
        }

    protected:
        Ref<Widget> m_Parent = nullptr;
        Rect m_Rect;
        std::vector<Ref<Widget>> m_Children;
    };

}