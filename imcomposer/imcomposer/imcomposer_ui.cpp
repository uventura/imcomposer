#include "imcomposer/imcomposer/imcomposer_ui.hpp"
#include "imcomposer/lib/core/imgui/imgui.hpp"

void ImComposer::ImComposerUi::render()
{
    ImComposer::Core::Imgui imgui(window_.getWindow());
    imgui_ = &imgui;

    bool show_demo_window = true;

    while(!window_.shouldClose())
    {
        clear();

        ImGui::ShowDemoWindow(&show_demo_window);

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
