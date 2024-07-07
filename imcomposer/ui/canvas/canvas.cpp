#include "imcomposer/ui/canvas/canvas.h"

ImComposer::UI::Canvas::Canvas() {}

void ImComposer::UI::Canvas::draw() {
    static ImGuiConfigFlags child_flag = ImGuiChildFlags_Border;
    static bool open = true;

    ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0.7058823529411765,0.8235294117647058,0.8509803921568627, 1.0f));
    ImGui::Begin("Canvas", &open);
        ImGui::PushStyleColor(ImGuiCol_ChildBg, ImVec4(0.23921568627450981,0.23921568627450981,0.23921568627450981, 1.0f));
        ImGui::BeginChild("Test 3226", ImVec2(150,150), child_flag);    
            ImGui::Button("Subbutton");
        ImGui::EndChild();
        ImGui::PopStyleColor();
    ImGui::End();
    ImGui::PopStyleColor();
}