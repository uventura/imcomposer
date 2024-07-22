#include "imcomposer/ui/properties/properties.h"
#include "imcomposer/core/fonts/fonts.h"

ImComposer::UI::Properties::Properties() {}

ImComposer::Event ImComposer::UI::Properties::draw() {
    ImComposer::Event event;

    ImGui::Begin("Properties");
        if(propertyExists_) {
            ImGui::Text("Title: %s", widgetData_->title().c_str());
        }
        else {
            ImGui::Text("No property available yet...");
        }
    ImGui::End();

    return event;
}

void ImComposer::UI::Properties::setWidgetData(ImComposer::Core::Parser::JsonWidgetReader* widgetData) {
    propertyExists_ = true;
    widgetData_ = widgetData;
}