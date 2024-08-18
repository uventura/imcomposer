#ifndef IMCOMPOSER_UI
#define IMCOMPOSER_UI

#include <string>

#include "imcomposer/core/imgui/imgui.h"
#include "imcomposer/core/window/window.h"
#include "imcomposer/ui/ui.h"

namespace ImComposer {
class ImComposerUi {
 private:
  ImComposer::Core::Window window_;
  ImComposer::Core::Imgui* imgui_;

  ImComposer::UI::MainUi ui_;

 public:
  void render();

 private:
  void clear();
  void update();
};
}  // namespace ImComposer

#endif
