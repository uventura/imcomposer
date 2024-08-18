#include "imcomposer/ui/menubar/menubar.h"

#include <iostream>

#include "imcomposer/core/fonts/fonts.h"
#include "imcomposer/core/imgui/imgui.h"

namespace ImComposer {
namespace UI {
Menubar::Menubar() { state_ = true; }

void Menubar::setIconFont(ImFont* font) { iconFont_ = font; }

void Menubar::begin() {
  if (ImGui::BeginMenuBar()) {
    ImGui::PushFont(
        ImComposer::Core::FontLoader::fonts[IMCOMPOSER_ICON_FONT_1]);
    ImGui::Text(ICON_CI_TOOLS);
    ImGui::PopFont();

    if (ImGui::BeginMenu("File")) {
      if (ImGui::MenuItem("New", "Ctrl+N")) {
        std::cout << "Create\n";
      }
      if (ImGui::MenuItem("Open", "Ctrl+O")) {
        std::cout << "Open\n";
      }
      if (ImGui::MenuItem("Save", "Ctrl+S")) {
        std::cout << "Save\n";
      }
      if (ImGui::MenuItem("Save as..", "Ctrl+Shift+S")) {
        std::cout << "Save As\n";
      }
      ImGui::EndMenu();
    }
    ImGui::EndMenuBar();
  }
}
}  // namespace UI
}  // namespace ImComposer
