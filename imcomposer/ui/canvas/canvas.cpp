#include "imcomposer/ui/canvas/canvas.h"

ImComposer::UI::Canvas::Canvas(const std::string& widgetPath, const int id):
    widgetPath_(widgetPath), id_(id) {
    widgetInstance_ = std::make_unique<Core::Parser::JsonWidgetReader>(widgetPath);
}

void ImComposer::UI::Canvas::draw() {
    static ImGuiConfigFlags child_flag = ImGuiChildFlags_Border;
    static bool open = true;

    ImGui::PushStyleColor(
        ImGuiCol_WindowBg,
        ImVec4(0.7058823529411765,0.8235294117647058,0.8509803921568627, 1.0f)
    );

    ImGui::Begin(widgetInstance_.get()->title().c_str(), &open);
        ImGui::PushStyleColor(
            ImGuiCol_ChildBg,
            ImVec4(0.23921568627450981,0.23921568627450981,0.23921568627450981, 1.0f)
        );

        ImGui::BeginChild(
            widgetInstance_.get()->title().c_str(),
            ImVec2(widgetInstance_.get()->width(),widgetInstance_.get()->height()),
            child_flag
        );
            widgetInstance_.get()->draw();

        ImGui::EndChild();
        ImGui::PopStyleColor();
    ImGui::End();
    ImGui::PopStyleColor();
}

const ImComposer::Core::Parser::JsonWidgetReader ImComposer::UI::Canvas::data() {
    return *widgetInstance_.get();
}