#include "imcomposer/ui/canvas/canvas.h"
#include "imcomposer/core/parser/json_widget_reader.h"

ImComposer::UI::Canvas::Canvas() {}

void ImComposer::UI::Canvas::draw() {
    static ImGuiConfigFlags child_flag = ImGuiChildFlags_Border;
    static bool open = true;

    ImComposer::Core::Parser::JsonWidgetReader widget("");

    ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0.7058823529411765,0.8235294117647058,0.8509803921568627, 1.0f));
    ImGui::Begin("Canvas", &open);
        ImGui::PushStyleColor(ImGuiCol_ChildBg, ImVec4(0.23921568627450981,0.23921568627450981,0.23921568627450981, 1.0f));
        ImGui::BeginChild(widget.title().c_str(), ImVec2(widget.width(),widget.height()), child_flag); 
            widget.draw();
        ImGui::EndChild();
        ImGui::PopStyleColor();
    ImGui::End();
    ImGui::PopStyleColor();
}