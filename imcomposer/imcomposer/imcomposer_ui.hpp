#ifndef IMCOMPOSER_UI
#define IMCOMPOSER_UI

#include "imcomposer/lib/core/window/window.hpp"

namespace ImComposer
{
    class ImComposerUi
    {
        private:
            ImComposer::Core::Window window_;

        public:
            void render();
    };
}

#endif
