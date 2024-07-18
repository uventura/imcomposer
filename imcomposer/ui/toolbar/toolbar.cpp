#include "imcomposer/ui/toolbar/toolbar.h"
#include "imcomposer/core/file_dialog/file_dialog.h"

#include <iostream>

ImComposer::UI::Toolbar::Toolbar() {}

void ImComposer::UI::Toolbar::draw() {
    static Core::FileDialog file;

    ImGui::Begin("Toolbar");
        ImGui::Button("New Widget");

        ImGui::SameLine();
        if(ImGui::Button("Load widget")) {
            file.openFile();
        }
    ImGui::End();

    if(file.isAborted()) {
        std::cout << "THe operation was aborted...\n";
        file.reset();
    }
}