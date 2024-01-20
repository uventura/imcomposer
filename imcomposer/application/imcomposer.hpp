#ifndef IMCOMPOSER_UI
#define IMCOMPOSER_UI

#include "imcomposer/core/window/window.hpp"
#include "imcomposer/core/imgui/imgui.hpp"

namespace ImComposer
{
    class ImComposerUi
    {
        private:
            ImComposer::Core::Window window_;
            ImComposer::Core::Imgui* imgui_;

            void clear();
            void update();
        public:
            void render();
    };
}

#endif
