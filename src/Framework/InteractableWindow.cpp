#include "InteractableWindow.h"

namespace rui {

    InteractableWindow::InteractableWindow(InteractableWindowCreateFlags flags)
        : m_Flags(std::move(flags))
    {
    }

    InteractableWindow::~InteractableWindow()
    {

    }


    Ref<Widget> InteractableWindow::GetRootWidget() const
    {
        if (m_Widgets.empty()) return nullptr;
        return m_Widgets.front();
    }
}
