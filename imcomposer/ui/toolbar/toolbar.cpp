#include "imcomposer/ui/toolbar/toolbar.h"

ImComposer::UI::Toolbar::Toolbar() {}

void ImComposer::UI::Toolbar::draw() {
    ImGui::Begin("Toolbar");
        ImGui::Button("New Widget");
    ImGui::End();
}