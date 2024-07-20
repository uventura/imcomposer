#include "imcomposer/core/parser/json_widget_reader.h"
#include "imcomposer/core/imgui/imgui.h"

#include <iostream>
#include <fstream>

ImComposer::Core::Parser::JsonWidgetReader::JsonWidgetReader(const std::string& location) {
    // An absolute path must be provided here, but this will be fixed.
    std::ifstream file(location);
    widgetParsed_ = json::parse(file);
    title_ = widgetParsed_["title"];
    width_ = widgetParsed_["width"];
    height_ = widgetParsed_["height"];
}

void ImComposer::Core::Parser::JsonWidgetReader::draw() {
    for(unsigned int item = 0; item < widgetParsed_["widgets"].size(); ++item) {
        auto element = widgetParsed_["widgets"][item];
        beginElement(element);
        endElement(element);
    }
}

void ImComposer::Core::Parser::JsonWidgetReader::beginElement(const json& element) {
    if(element["type"] == "button") {
        std::string text = element["text"]; 
        ImGui::Button(text.c_str());
    }
}

void ImComposer::Core::Parser::JsonWidgetReader::endElement(const json& element) {

}