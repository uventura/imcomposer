#include "imcomposer/application/imcomposer.hpp"
#include "imcomposer/core/imgui/imgui.hpp"
#include "imcomposer/components/docking/docking.hpp"

#include "third_party/material_design_icon/material_design_icon.h"
#include "third_party/material_design_icon/font_awesome_design.h"
#include "third_party/material_design_icon/IconsCodicons.h"
#include "third_party/material_design_icon/IconsLucide.h"
#include "third_party/material_design_icon/IconsForkAwesome.h"

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
        // ImGui::Button(ICON_FA_FILE);
        // ImGui::Button(ICON_FA_FILE_IMPORT);
        // ImGui::Button(ICON_FA_FILE_PDF);
        // ImGui::Button(ICON_FK_HEART, ImVec2(40, 40));

        ImGui::Button(ICON_CI_FILE_TEXT, ImVec2(60, 60));
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
