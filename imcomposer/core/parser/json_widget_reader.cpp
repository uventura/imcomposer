#include "imcomposer/core/parser/json_widget_reader.h"
#include "imcomposer/core/imgui/imgui.h"

#include <iostream>
#include <fstream>

ImComposer::Core::Parser::JsonWidgetReader::JsonWidgetReader(const std::string& location) {
    std::ifstream file(location);
    widgetParsed_ = json::parse(file);
    title_ = widgetParsed_["title"];
    width_ = widgetParsed_["width"];
    height_ = widgetParsed_["height"];
    file.close();
}

void ImComposer::Core::Parser::JsonWidgetReader::draw() {
    for(unsigned int item = 0; item < widgetParsed_["widgets"].size(); ++item) {
        auto element = widgetParsed_["widgets"][item];
        beginElement(element);
        endElement(element);
    }
}

void ImComposer::Core::Parser::JsonWidgetReader::beginElement(const json& element) {
    auto drawList = ImGui::GetWindowDrawList();
    const ImVec2 initialPosition = ImGui::GetCursorScreenPos();

    if(element["type"] == "button") {
        std::string text = element["text"]; 
        ImGui::Button(text.c_str());
    }
    else if(element["type"] == "text") {
        std::string text = element["text"];
        ImGui::Text("%s", text.c_str());
    }

    if(ImGui::IsItemClicked()
    ||(selectedItemExists_ && selectedItem_["id"] == element["id"])) {
        selectedItem_ = element;
        selectedItemExists_ = true;

        auto itemDimensions = ImGui::GetItemRectSize();
        static ImVec4 colf = ImVec4(1.0f, 1.0f, 0.4f, 1.0f);
        const ImU32 col = ImColor(colf);
        const int spacement = 2;

        drawList->AddRect(
            ImVec2(
                initialPosition.x - spacement,
                initialPosition.y - spacement
            ),
            ImVec2(
                initialPosition.x + itemDimensions.x + spacement,
                initialPosition.y + itemDimensions.y + spacement
            ),
            col
        );
    }
}

void ImComposer::Core::Parser::JsonWidgetReader::endElement(const json& element) {

}