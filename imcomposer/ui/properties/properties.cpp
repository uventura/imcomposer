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
            json element = *widgetElement_;
            std::string title = element["id"];

            ImGui::Text("Title: %s", title.c_str());
            if(element["type"] == "widget")
            {
                for(long long i = 0; i < element["widgets"].size(); ++i)
                {
                    json item = element["widgets"][i];
                    std::string id = item["id"];
                    ImGui::Text("Element: %s", id.c_str());
                }
            }
        }
        else {
            ImGui::Text("No property available yet...");
        }
    ImGui::End();

    return event;
}

void Properties::setJsonElement(json& widgetElement) {
    propertyExists_ = true;
    widgetElement_ = &widgetElement;
}
}
}