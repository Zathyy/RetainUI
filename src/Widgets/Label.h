#pragma once

#include "Widget.h"

namespace rui {

    class RUI_API Label : public Widget
    {
    public:
        void SetText(const String& text);

    private:
        String m_Text;
    };

}
