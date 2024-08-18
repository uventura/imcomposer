#include "imcomposer/core/imgui/imgui.h"

#include <GLFW/glfw3.h>
#include <glad/gl.h>

#include <iostream>

#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"
#include "imgui.h"

ImComposer::Core::Imgui::Imgui(GLFWwindow* window) {
  window_ = window;

  // Setup Dear ImGui context
  IMGUI_CHECKVERSION();
  context_ = ImGui::CreateContext();

  io = &ImGui::GetIO();
  (void)io;
  io->ConfigFlags |=
      ImGuiConfigFlags_NavEnableKeyboard;  // Enable Keyboard Controls
  io->ConfigFlags |= ImGuiConfigFlags_DockingEnable;  // Enable Docking
  // io->ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;         // Enable
  // Multi-Viewport / Platform Windows
  io->ConfigFlags |= ImGuiConfigFlags_DockingEnable;  // Enable Docking

  // Setup Dear ImGui style
  ImGui::StyleColorsDark();

  ImGuiStyle& style = ImGui::GetStyle();
  if (io->ConfigFlags & ImGuiConfigFlags_ViewportsEnable) {
    style.WindowRounding = 0.0f;
    style.Colors[ImGuiCol_WindowBg].w = 1.0f;
  }

  // Setup Platform/Renderer backends
  const char* glsl_version = "#version 130";
  ImGui_ImplGlfw_InitForOpenGL(window, true);
  ImGui_ImplOpenGL3_Init(glsl_version);

  font_.load();
}

ImComposer::Core::Imgui::~Imgui() {
  ImGui_ImplOpenGL3_Shutdown();
  ImGui_ImplGlfw_Shutdown();
  ImGui::DestroyContext();
}

void ImComposer::Core::Imgui::newFrame() {
  ImGui_ImplOpenGL3_NewFrame();
  ImGui_ImplGlfw_NewFrame();
  ImGui::NewFrame();
}

void ImComposer::Core::Imgui::render() { ImGui::Render(); }

void ImComposer::Core::Imgui::update() {
  ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

  // Update and Render additional Platform Windows
  // (Platform functions may change the current OpenGL context, so we
  // save/restore it to make it easier to paste this code elsewhere.
  //  For this specific demo app we could also call
  //  glfwMakeContextCurrent(window) directly)
  if (io->ConfigFlags & ImGuiConfigFlags_ViewportsEnable) {
    GLFWwindow* backup_current_context = glfwGetCurrentContext();
    ImGui::UpdatePlatformWindows();
    ImGui::RenderPlatformWindowsDefault();
    glfwMakeContextCurrent(backup_current_context);
  }
}
