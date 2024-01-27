#include "imcomposer/application/imcomposer.hpp"
#include "imcomposer/core/imgui/imgui.hpp"
#include "imcomposer/components/docking/docking.hpp"

#include "data/fonts/fonts.h"

#include <iostream>
#include <string>

ImComposer::ImComposerUi::ImComposerUi(std::string applicationPath)
{
    applicationPath_ = applicationPath;
}

void ImComposer::ImComposerUi::render()
{
    ImComposer::Core::Imgui imgui(window_.getWindow(), applicationPath_);
    imgui_ = &imgui;

    bool show_demo_window = true;

    while(!window_.shouldClose())
    {
        clear();
        ImComposer::Component::Docking::begin();

        ImGui::ShowDemoWindow(&show_demo_window);

        ImGui::Begin("Something");
        ImGui::Button(ICON_CI_HEART, ImVec2(60, 60));
        ImGui::End();

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
