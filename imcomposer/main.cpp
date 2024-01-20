#include "imcomposer/lib/core/window/window.h"

int main()
{
    ImComposer::Window window;

    while(!window.shouldClose())
    {
        window.clear();

        // Something

        window.bufferUpdate();
        window.renderUpdate();
    }
}
