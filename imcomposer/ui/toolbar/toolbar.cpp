#include "imcomposer/ui/toolbar/toolbar.h"

#include <iostream>

namespace ImComposer {
namespace UI {
Toolbar::Toolbar() {}

ImComposer::Event Toolbar::draw() {
  ImComposer::Event event;

  ImGui::Begin("Toolbar");
  ImGui::Button("New Widget");

  ImGui::SameLine();
  if (ImGui::Button("Load widget")) {
    event = {
        ImComposer::EventType::FileEvent,
        ImComposer::EventAction::File::Open,
    };
  }
  ImGui::End();

  return event;
}
}  // namespace UI
}  // namespace ImComposer