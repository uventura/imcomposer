#include "imcomposer/ui/canvas/canvas.h"

ImComposer::UI::Canvas::Canvas() {}

void ImComposer::UI::Canvas::draw() {
    static ImGuiConfigFlags flags = ImGuiWindowFlags_NoBackground;
    static ImGuiConfigFlags child_flag = ImGuiChildFlags_Border;
    static bool open = true;
    ImGui::Begin("Canvas", &open, flags);
        ImGui::BeginChild("Test 3226", ImVec2(50,50), child_flag);    
            ImGui::Button("Subbutton");
        ImGui::EndChild();
    ImGui::End();
}