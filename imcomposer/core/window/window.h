#ifndef IMCOMPOSER_CORE_WINDOW
#define IMCOMPOSER_CORE_WINDOW

#include <GLFW/glfw3.h>
#include <glad/gl.h>

#include <string>

namespace ImComposer {
namespace Core {
class Window {
 private:
  const int glfwMajorVersion_ = 3;
  const int glfwMinorVersion_ = 0;
  const int glfwMaximized_ = 1;

  const std::string title_ = "ImComposer";
  const int width_ = 640;
  const int height_ = 480;
  GLFWwindow* window_;
  const float backgroundColor_[4] = {0.03f, 0.0f, 0.1f, 0.03f};

 public:
  Window();
  ~Window();

  void clear();
  void bufferUpdate();
  void renderUpdate();
  inline int shouldClose() { return glfwWindowShouldClose(window_); };

  inline GLFWwindow* getWindow() { return window_; };
};
}  // namespace Core
}  // namespace ImComposer

#endif
