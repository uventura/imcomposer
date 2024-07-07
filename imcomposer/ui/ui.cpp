#include "imcomposer/ui/ui.h"
#include "imcomposer/core/imgui/imgui.h"
#include "imcomposer/core/fonts/fonts.h"

ImComposer::UI::MainUi::MainUi() {}

void ImComposer::UI::MainUi::draw() {
    menubar_.begin();

    toolbar_.draw();
    canvas_.draw();
    // ImGui::ShowDemoWindow(&show_demo_window);

    ImGui::PushFont(ImComposer::Core::FontLoader::fonts[IMCOMPOSER_ICON_FONT_1]);
        ImGui::Text(ICON_CI_TOOLS);

    ImGui::Begin("Something");
    ImGui::Button(ICON_CI_HEART, ImVec2(60, 60));
    ImGui::End();

    ImGui::PopFont();
}