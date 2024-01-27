#ifndef IMCOMPOSER_UI
#define IMCOMPOSER_UI

#include "imcomposer/core/window/window.hpp"
#include "imcomposer/core/imgui/imgui.hpp"

#include "imcomposer/ui/toolbar/toolbar.h"

#include <string>

namespace ImComposer
{
    class ImComposerUi
    {
        private:
            ImComposer::Core::Window window_;
            ImComposer::Core::Imgui* imgui_;

            ImComposer::Component::Toolbar toolbar_;

        public:
            void render();

        private:
            void clear();
            void update();
    };
}

#endif
