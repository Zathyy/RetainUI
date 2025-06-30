#pragma once

namespace rui {

    class Example
    {
    public:
        Example();
        ~Example();

        void Loop();

        void Render();
    };
}

int main()
{
    rui::Example example{};

    return 0;
}
