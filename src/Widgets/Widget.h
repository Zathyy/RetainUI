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

    bool OnMouseMove(int32 x, int32 y);
    bool OnMouseDown(int32 x, int32 y);
    bool OnMouseUp(int32 x, int32 y);
    bool OnMouseLeave();
    bool OnMouseEnter();

    void SetParent(Ref<Widget> parent);
    void SetRect(const Rect& rect);

public:

    FORCE_INLINE Widget* GetParent() const
    {
        return m_Parent.get();
    }
    FORCE_INLINE Rect GetRect() const {
        return m_Rect;
    }

protected:
    Ref<Widget> m_Parent = nullptr;
    Rect m_Rect;
};

}