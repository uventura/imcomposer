#ifndef IMCOMPOSER_CORE_IMGUI
#define IMCOMPOSER_CORE_IMGUI

#include <string>
#include <map>

#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include "imgui.h"
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"

#include "imcomposer/core/fonts/font_loader.h"

namespace ImComposer
{
namespace Core
{
    class Imgui
    {
        private:
            GLFWwindow* window_;
            ImGuiIO* io;
            ImComposer::Core::FontLoader font_;

        public:
            Imgui(GLFWwindow* window);
            ~Imgui();

            void newFrame();
            void render();
            void update();
    };
}
}

#endif
