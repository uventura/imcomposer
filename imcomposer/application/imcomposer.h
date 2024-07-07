#ifndef IMCOMPOSER_UI
#define IMCOMPOSER_UI

#include "imcomposer/core/window/window.h"
#include "imcomposer/core/imgui/imgui.h"

#include "imcomposer/ui/ui.h"

#include <string>

namespace ImComposer
{
    class ImComposerUi
    {
        private:
            ImComposer::Core::Window window_;
            ImComposer::Core::Imgui* imgui_;

            ImComposer::UI::MainUi ui_;

        public:
            void render();

        private:
            void clear();
            void update();
    };
}

#endif
