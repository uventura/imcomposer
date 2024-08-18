#include "imcomposer/ui/properties/properties.h"
#include "imcomposer/core/fonts/fonts.h"

#include <string>

namespace ImComposer
{
namespace UI
{
Properties::Properties() {}

Event Properties::draw() {
    ImComposer::Event event;

    ImGui::Begin("Properties");
        if(propertyExists_) {
            std::string title = widgetElement_["id"];
            ImGui::Text("Title: %s", title.c_str());
        }
        else {
            ImGui::Text("No property available yet...");
        }
    ImGui::End();

    return event;
}

void Properties::setJsonElement(json widgetElement) {
    propertyExists_ = true;
    widgetElement_ = widgetElement;
}
}
}