#include "imcomposer/main/imcomposer.hpp"
#include "imcomposer/core/imgui/imgui.hpp"
#include "imcomposer/components/docking/docking.hpp"

void ImComposer::ImComposerUi::render()
{
    ImComposer::Core::Imgui imgui(window_.getWindow());
    imgui_ = &imgui;

    bool show_demo_window = true;

    while(!window_.shouldClose())
    {
        clear();
        ImComposer::Component::Docking::begin();

        ImGui::ShowDemoWindow(&show_demo_window);

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
