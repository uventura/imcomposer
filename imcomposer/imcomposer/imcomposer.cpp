#include "imcomposer/imcomposer/imcomposer.hpp"

void ImComposer::ImComposer::render()
{
    while(!window_.shouldClose())
    {
        window_.clear();

        // Something

        window_.bufferUpdate();
        window_.renderUpdate();
    }
}
