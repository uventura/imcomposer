#ifndef IMCOMPOSER_CORE_IMGUI
#define IMCOMPOSER_CORE_IMGUI

#include <string>
#include <map>

#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include "imgui.h"
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"

namespace ImComposer
{
namespace Core
{
    class Imgui
    {
        private:
            std::string applicationPath_;

            GLFWwindow* window_;
            ImGuiIO* io;
            std::map<std::string, ImFont*> fonts_;

            void loadFonts();
        public:
            Imgui(GLFWwindow* window, std::string applicationPath);
            ~Imgui();

            void newFrame();
            void render();
            void update();

            inline ImFont* getFont(std::string font){return fonts_[font];};
    };
}
}

#endif
