#include "imcomposer/core/imgui/imgui.h"
#include "imcomposer/ui/toolbar/toolbar.h"

#include "imcomposer/core/fonts/fonts.h"

#include <iostream>

ImComposer::Component::Toolbar::Toolbar()
{
    state_ = true;
}

void ImComposer::Component::Toolbar::setIconFont(ImFont* font)
{
    iconFont_ = font;
}

void ImComposer::Component::Toolbar::begin()
{
    if (ImGui::BeginMenuBar())
    {
        ImGui::PushFont(ImComposer::Core::FontLoader::fonts[IMCOMPOSER_ICON_FONT_1]);
            ImGui::Text(ICON_CI_TOOLS);
        ImGui::PopFont();

        if (ImGui::BeginMenu("File"))
        {
            if (ImGui::MenuItem("New", "Ctrl+N"))
            {
                std::cout << "Create\n";
            }
            if (ImGui::MenuItem("Open", "Ctrl+O"))
            {
                std::cout << "Open\n";
            }
            if (ImGui::MenuItem("Save", "Ctrl+S"))
            {
                std::cout << "Save\n";
            }
            if (ImGui::MenuItem("Save as..", "Ctrl+Shift+S"))
            {
                std::cout << "Save As\n";
            }
            ImGui::EndMenu();
        }
        ImGui::EndMenuBar();
    }
}

