#include "imcomposer/ui/properties/properties.h"
#include "imcomposer/core/fonts/fonts.h"

ImComposer::UI::Properties::Properties() {}

ImComposer::Event ImComposer::UI::Properties::draw() {
    ImComposer::Event event;

    ImGui::Begin("Properties");
        static bool show_demo_window = true;
        ImGui::ShowDemoWindow(&show_demo_window);

        ImGui::PushFont(ImComposer::Core::FontLoader::fonts[IMCOMPOSER_ICON_FONT_1]);
            ImGui::Text(ICON_CI_TOOLS);

        ImGui::Begin("Something");
        ImGui::Button(ICON_CI_HEART, ImVec2(60, 60));
        ImGui::End();

        ImGui::PopFont();
    ImGui::End();

    return event;
}