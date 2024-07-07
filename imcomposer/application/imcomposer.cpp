#include "imcomposer/application/imcomposer.hpp"
#include "imcomposer/core/imgui/imgui.hpp"
#include "imcomposer/core/imgui/docking.hpp"
#include "imcomposer/core/fonts/fonts.h"

#include "data/fonts/fonts.h"

#include <iostream>
#include <string>

#include "imcomposer/application/imcomposer_environment.h"

void ImComposer::ImComposerUi::render()
{
    ImComposer::Core::Imgui imgui(window_.getWindow());
    imgui_ = &imgui;

    // bool show_demo_window = true;

    while(!window_.shouldClose())
    {
        clear();
        ImComposer::Component::Docking::begin();

        toolbar_.begin();

        // ImGui::ShowDemoWindow(&show_demo_window);

        ImGui::PushFont(ImComposer::Core::FontLoader::fonts[IMCOMPOSER_ICON_FONT_1]);
            ImGui::Text(ICON_CI_TOOLS);

        ImGui::Begin("Something");
        ImGui::Button(ICON_CI_HEART, ImVec2(60, 60));
        ImGui::End();

        ImGui::PopFont();

        ImComposer::Component::Docking::end();

        update();
    }
}

void ImComposer::ImComposerUi::clear()
{
    window_.clear();
    imgui_->newFrame();
}

void ImComposer::ImComposerUi::update()
{
    imgui_->render();
    window_.renderUpdate();

    imgui_->update();
    window_.bufferUpdate();
}
