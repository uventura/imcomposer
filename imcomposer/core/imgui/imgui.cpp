#include "imcomposer/core/imgui/imgui.hpp"
#include "imcomposer/utils/bazel.h"

#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "imgui.h"
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"

#include "data/fonts/fonts.h"

ImComposer::Core::Imgui::Imgui(GLFWwindow* window, std::string applicationPath)
{
    applicationPath_ = applicationPath;
    window_ = window;

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();

    io = &ImGui::GetIO(); (void)io;
    io->ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;       // Enable Keyboard Controls
    io->ConfigFlags |= ImGuiConfigFlags_DockingEnable;           // Enable Docking
    io->ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;         // Enable Multi-Viewport / Platform Windows
    io->ConfigFlags |= ImGuiConfigFlags_DockingEnable;           // Enable Docking

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();

    ImGuiStyle& style = ImGui::GetStyle();
    if (io->ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
    {
        style.WindowRounding = 0.0f;
        style.Colors[ImGuiCol_WindowBg].w = 1.0f;
    }

    // Setup Platform/Renderer backends
    const char* glsl_version = "#version 130";
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);

    loadFonts();
}

ImComposer::Core::Imgui::~Imgui()
{
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}

void ImComposer::Core::Imgui::newFrame()
{
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
}

void ImComposer::Core::Imgui::render()
{
    ImGui::Render();
}

void ImComposer::Core::Imgui::update()
{
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    // Update and Render additional Platform Windows
    // (Platform functions may change the current OpenGL context, so we save/restore it to make it easier to paste this code elsewhere.
    //  For this specific demo app we could also call glfwMakeContextCurrent(window) directly)
    if (io->ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
    {
        GLFWwindow* backup_current_context = glfwGetCurrentContext();
        ImGui::UpdatePlatformWindows();
        ImGui::RenderPlatformWindowsDefault();
        glfwMakeContextCurrent(backup_current_context);
    }
}

void ImComposer::Core::Imgui::loadFonts()
{
    // Configuring Font
    ImFontConfig config;
    config.MergeMode = true;
    config.GlyphOffset = { 0.f, 5.f };

    std::map<std::string, std::string> loadedFonts; // Used for readbility purposes
    loadedFonts["robotoMedium"] = ImComposer::Utils::Bazel::getFullPath(applicationPath_, ROBOTO_REGULAR);
    loadedFonts["codiIcon"] = ImComposer::Utils::Bazel::getFullPath(applicationPath_, CODI_ICONS_VSCODE);

	auto& io = ImGui::GetIO();
    // ImFont* font = io.Fonts->AddFontDefault();
    io.Fonts->AddFontFromFileTTF(loadedFonts["robotoMedium"].c_str(), 20.0f);

    // Codi Icon
    static const ImWchar icons_ranges_cod[] = { ICON_MIN_CI, ICON_MAX_16_CI, 0 };
    fonts_["codiIcon"] = io.Fonts->AddFontFromFileTTF(loadedFonts["codiIcon"].c_str(), 30.0f, &config, icons_ranges_cod);

    // Merging Fonts
    io.Fonts->Build();
    config.MergeMode = false;
}
