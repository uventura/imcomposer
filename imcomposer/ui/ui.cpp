#include "imcomposer/ui/ui.h"

#include <iostream>

#include "imcomposer/core/fonts/fonts.h"
#include "imcomposer/core/imgui/imgui.h"
#include "imcomposer/events/events.h"

namespace ImComposer {
namespace UI {
MainUi::MainUi() {}

void MainUi::draw() {
  menubar_.begin();

  eventChecker(toolbar_.draw());
  drawCanvas();
  eventChecker(properties_.draw());

  ImGui::Begin("Debug Window");
  ImGuiContext& g = *GImGui;
  ImGui::Text("%d", ImGui::GetHoveredID());
  ImGui::End();

  static bool open = true;
  ImGui::ShowDemoWindow(&open);

  eventAction();
}

void MainUi::eventChecker(ImComposer::Event event) {
  switch (event.type) {
    case ImComposer::EventType::None:
      break;
    case ImComposer::EventType::FileEvent:
      fileEvent(event.event);
      break;
    case ImComposer::EventType::WidgetEvent:
      break;
  }
}

void MainUi::eventAction() {
  if (file_.isReady()) {
    auto newId = openedCanvas_.size() + 1;
    openedCanvas_.push_back(Canvas(file_.getValue(), newId));
    currentCanvas_ = newId;
    file_.reset();
  }
}

void MainUi::fileEvent(ImComposer::EventActionValue eventAction) {
  if (eventAction == ImComposer::EventAction::File::Open) {
    file_.openFile();
  }
}

void MainUi::drawCanvas() {
  for (int i = 0; i < openedCanvas_.size(); ++i) {
    if (currentCanvas_ == openedCanvas_[i].id()) {
      properties_.setJsonElement(openedCanvas_[i].widget());
    }

    openedCanvas_[i].draw();
  }
}
}  // namespace UI
}  // namespace ImComposer