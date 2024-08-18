#include <nlohmann/json.hpp>

#include "imcomposer/core/imgui/imgui.h"
#include "imcomposer/core/parser/json_widget_reader.h"
#include "imcomposer/events/events.h"

namespace ImComposer {
namespace UI {
using json = nlohmann::json;

class Properties {
 public:
  Properties();
  ImComposer::Event draw();

  void setJsonElement(json& widgetElement);

 private:
  bool propertyExists_{false};
  json* widgetElement_{nullptr};
};
}  // namespace UI
}  // namespace ImComposer
