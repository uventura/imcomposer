
#include "imcomposer/core/window/window.h"

#include <GLFW/glfw3.h>
#include <glad/gl.h>

#include <iostream>

ImComposer::Core::Window::Window() {
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, glfwMajorVersion_);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, glfwMinorVersion_);
  glfwWindowHint(GLFW_MAXIMIZED, glfwMaximized_);

  if (!glfwInit()) {
    return;
  }

  // glfwWindowHint(GLFW_DECORATED, false);

  window_ = glfwCreateWindow(width_, height_, title_.c_str(), nullptr, nullptr);
  glfwMaximizeWindow(window_);

  if (!window_) {
    glfwTerminate();
    return;
  }

  glfwMakeContextCurrent(window_);
  gladLoadGL(glfwGetProcAddress);
  glfwSwapInterval(2);
}

ImComposer::Core::Window::~Window() {
  glfwDestroyWindow(window_);
  glfwTerminate();
}

void ImComposer::Core::Window::clear() {
  glClear(GL_COLOR_BUFFER_BIT);
  glClearColor(backgroundColor_[0], backgroundColor_[1], backgroundColor_[2],
               backgroundColor_[3]);
}

void ImComposer::Core::Window::renderUpdate() {
  int display_w, display_h;
  glfwGetFramebufferSize(window_, &display_w, &display_h);
  glViewport(0, 0, display_w, display_h);
}

void ImComposer::Core::Window::bufferUpdate() {
  glfwPollEvents();
  glfwSwapBuffers(window_);
}
