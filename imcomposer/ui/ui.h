#pragma once

#include <memory>
#include <vector>

#include "imcomposer/core/file_dialog/file_dialog.h"
#include "imcomposer/events/events.h"
#include "imcomposer/ui/canvas/canvas.h"
#include "imcomposer/ui/menubar/menubar.h"
#include "imcomposer/ui/properties/properties.h"
#include "imcomposer/ui/toolbar/toolbar.h"

namespace ImComposer {
namespace UI {
class MainUi {
 public:
  MainUi();
  void draw();

 private:
  bool state_;
  Menubar menubar_;
  Toolbar toolbar_;
  Properties properties_;

  std::vector<Canvas> openedCanvas_;

 private:
  void eventChecker(ImComposer::Event event);
  void eventAction();
  void drawCanvas();

  void fileEvent(ImComposer::EventActionValue eventAction);

 private:
  Core::FileDialog file_;
  int currentCanvas_{-1};
};
}  // namespace UI
}  // namespace ImComposer
