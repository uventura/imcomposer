#include "imcomposer/ui/properties/properties.h"

#include <string>

#include "imcomposer/core/fonts/fonts.h"

namespace ImComposer {
namespace UI {
Properties::Properties() {}

Event Properties::draw() {
  ImComposer::Event event;

  ImGui::Begin("Properties");
  if (propertyExists_) {
    drawWidgetProperty();
  } else {
    ImGui::Text("No property available yet...");
  }
  ImGui::End();

  return event;
}

void Properties::setJsonElement(json& widget) {
  propertyExists_ = true;
  widgetElement_ = &widget;
}

void Properties::drawWidgetProperty() {
    json element = *widgetElement_;

    std::string title = element["id"];
    ImGui::Text("Id: %s", title.c_str());

    if (element["type"] == "widget")
        drawRootWidgetProperties(widgetElement_);
    else if(element["type"] == "button")
        drawButtonProperties(widgetElement_);
    else if(element["type"] == "text") {
        std::string text = element["text"];
        ImGui::Text("Text Value: %s", text.c_str());

        char ctext[text.size() + 1];
        for(int i = 0; i < text.size(); i++)
            ctext[i] = text[i];
        ctext[text.size()] = '\0';

        ImGui::InputText("Text", ctext, text.size());
        (*widgetElement_)["text"] = std::string(ctext);        
    }
}   

void Properties::drawRootWidgetProperties(json* widget) {
    json element = *widgetElement_;

    for (long long i = 0; i < element["widgets"].size(); ++i) {
        json item = element["widgets"][i];
        std::string id = item["id"];
        ImGui::Text("Element: %s", id.c_str());
    }
}

void Properties::drawButtonProperties(json* widget) {

}
}  // namespace UI
}  // namespace ImComposer