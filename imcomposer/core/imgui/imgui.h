#ifndef IMCOMPOSER_CORE_IMGUI
#define IMCOMPOSER_CORE_IMGUI

#include <GLFW/glfw3.h>
#include <glad/gl.h>

#include <map>
#include <string>

#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"
#include "imcomposer/core/fonts/font_loader.h"
#include "imgui.h"
#include "imgui_internal.h"

namespace ImComposer {
namespace Core {
class Imgui {
 private:
  GLFWwindow* window_;
  ImGuiIO* io;
  ImGuiContext* context_;
  ImComposer::Core::FontLoader font_;

 public:
  Imgui(GLFWwindow* window);
  ~Imgui();

  void newFrame();
  void render();
  void update();
  inline const ImGuiContext* getContext() { return context_; };
};
}  // namespace Core
}  // namespace ImComposer

#endif
