#include "imcomposer/application/imcomposer.h"

#include <iostream>
#include <string>

#include "data/fonts/fonts.h"
#include "imcomposer/application/imcomposer_environment.h"
#include "imcomposer/core/fonts/fonts.h"
#include "imcomposer/core/imgui/docking.h"
#include "imcomposer/core/imgui/imgui.h"

void ImComposer::ImComposerUi::render() {
  ImComposer::Core::Imgui imgui(window_.getWindow());
  imgui_ = &imgui;

  // bool show_demo_window = true;

  while (!window_.shouldClose()) {
    clear();

    ImComposer::Component::Docking::begin();
    ui_.draw();
    ImComposer::Component::Docking::end();

    update();
  }
}

void ImComposer::ImComposerUi::clear() {
  window_.clear();
  imgui_->newFrame();
}

void ImComposer::ImComposerUi::update() {
  imgui_->render();
  window_.renderUpdate();

  imgui_->update();
  window_.bufferUpdate();
}
