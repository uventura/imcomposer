#include "imcomposer/imcomposer/imcomposer_ui.hpp"

void ImComposer::ImComposerUi::render()
{
    while(!window_.shouldClose())
    {
        window_.clear();

        // Something

        window_.bufferUpdate();
        window_.renderUpdate();
    }
}
