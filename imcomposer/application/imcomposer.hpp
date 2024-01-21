#ifndef IMCOMPOSER_UI
#define IMCOMPOSER_UI

#include "imcomposer/core/window/window.hpp"
#include "imcomposer/core/imgui/imgui.hpp"

#include <string>

namespace ImComposer
{
    class ImComposerUi
    {
        private:
            std::string applicationPath_;

            ImComposer::Core::Window window_;
            ImComposer::Core::Imgui* imgui_;

            void clear();
            void update();
        public:
            ImComposerUi(std::string applicationPath);
            void render();
    };
}

#endif
