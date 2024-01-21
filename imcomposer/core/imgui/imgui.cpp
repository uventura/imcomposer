#include "imcomposer/core/imgui/imgui.hpp"
#include "imcomposer/utils/bazel.h"

#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "imgui.h"
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"

#include "third_party/material_design_icon/material_design_icon.h"
#include "third_party/material_design_icon/font_awesome_design.h"
#include "third_party/material_design_icon/IconsCodicons.h"
#include "third_party/material_design_icon/IconsLucide.h"
#include "third_party/material_design_icon/IconsForkAwesome.h"

#define ROBOTO_REGULAR "imcomposer/third_party/material_design_icon/Roboto-Regular.ttf"
#define FA_REGULAR_400 "imcomposer/third_party/material_design_icon/fa-regular-400.ttf"
#define FA_REGULAR_900 "imcomposer/third_party/material_design_icon/fa-solid-900.ttf"
#define MATERIAL_ICON_REGULAR "imcomposer/third_party/material_design_icon/MaterialIcons-Regular.ttf"
#define CODI_ICONS_VSCODE "imcomposer/third_party/material_design_icon/codicon.ttf"
#define LUCIDE_ICONS "imcomposer/third_party/material_design_icon/lucide.ttf"
#define FORK_ICONS "imcomposer/third_party/material_design_icon/forkawesome-webfont.ttf"

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
    std::map<std::string, std::string> loadedFonts;

    loadedFonts["robotoMedium"] = ImComposer::Utils::Bazel::getFullPath(applicationPath_, ROBOTO_REGULAR);
    loadedFonts["faRegular400"] = ImComposer::Utils::Bazel::getFullPath(applicationPath_, FA_REGULAR_400);
    loadedFonts["faRegular900"] = ImComposer::Utils::Bazel::getFullPath(applicationPath_, FA_REGULAR_900);
    loadedFonts["materialIcon"] = ImComposer::Utils::Bazel::getFullPath(applicationPath_, MATERIAL_ICON_REGULAR);
    loadedFonts["codiIcon"] = ImComposer::Utils::Bazel::getFullPath(applicationPath_, CODI_ICONS_VSCODE);
    loadedFonts["lucide"] = ImComposer::Utils::Bazel::getFullPath(applicationPath_, LUCIDE_ICONS);
    loadedFonts["fork"] = ImComposer::Utils::Bazel::getFullPath(applicationPath_, FORK_ICONS);

	auto& io = ImGui::GetIO();
    // ImFont* font = io.Fonts->AddFontDefault();
    io.Fonts->AddFontFromFileTTF(loadedFonts["robotoMedium"].c_str(), 20.0f);

    static const ImWchar icons_ranges_fa[] = { ICON_MIN_FA, ICON_MAX_16_FA, 0 }; // Will not be copied by AddFont* so keep in scope.
    static const ImWchar icons_ranges[] = { ICON_MIN_MD, ICON_MAX_16_MD, 0 }; // Will not be copied by AddFont* so keep in scope.
    static const ImWchar icons_ranges_cod[] = { ICON_MIN_CI, ICON_MAX_16_CI, 0 }; // Will not be copied by AddFont* so keep in scope.
    static const ImWchar icons_ranges_lucide[] = { ICON_MIN_LC, ICON_MAX_16_LC, 0 }; // Will not be copied by AddFont* so keep in scope.
    static const ImWchar icons_ranges_fork[] = { ICON_MIN_FK, ICON_MAX_16_FK, 0 }; // Will not be copied by AddFont* so keep in scope.

    ImFontConfig config;
    config.MergeMode = true;
    config.GlyphOffset = { 0.f, 5.f };
    // config.PixelSnapH = true;
    // fonts_["faRegular400"] = io.Fonts->AddFontFromFileTTF(loadedFonts["faRegular400"].c_str(), 15.0f, &config, icons_ranges_fa);
    // fonts_["faRegular900"] = io.Fonts->AddFontFromFileTTF(loadedFonts["faRegular900"].c_str(), 15.0f, &config, icons_ranges_fa);
    // fonts_["materialIcon"] = io.Fonts->AddFontFromFileTTF(loadedFonts["materialIcon"].c_str(), 18.0f, &config, icons_ranges);
    fonts_["codiIcon"] = io.Fonts->AddFontFromFileTTF(loadedFonts["codiIcon"].c_str(), 30.0f, &config, icons_ranges_cod);
    // fonts_["lucide"] = io.Fonts->AddFontFromFileTTF(loadedFonts["lucide"].c_str(), 50.0f, &config, icons_ranges_lucide);
    // fonts_["fork"] = io.Fonts->AddFontFromFileTTF(loadedFonts["fork"].c_str(), 60.0f, &config, icons_ranges_fork);
    io.Fonts->Build();
}
