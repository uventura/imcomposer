#include "imcomposer/core/fonts/font_loader.h"

#include <iostream>

#include "imcomposer/application/imcomposer_environment.h"
#include "imcomposer/core/fonts/available_fonts.h"
#include "imcomposer/utils/bazel.h"
#include "imgui.h"

std::map<std::string, ImFont*> ImComposer::Core::FontLoader::fonts;

void ImComposer::Core::FontLoader::load() {
  loadFont(IMCOMPOSER_DEFAULT_FONT, ROBOTO_REGULAR, 17.0);
  loadGlyphs(IMCOMPOSER_ICON_FONT_1, CODI_ICONS_VSCODE, ICON_MIN_CI,
             ICON_MAX_16_CI, 15.0f, 0.f, 1.f);
}

void ImComposer::Core::FontLoader::loadFont(std::string name, std::string path,
                                            float size) {
  std::string fullPath = ImComposer::Utils::Bazel::getFullPath(
      ImComposer::Environment::applicationPath, path);

  auto& io = ImGui::GetIO();
  ImComposer::Core::FontLoader::fonts[name] =
      io.Fonts->AddFontFromFileTTF(fullPath.c_str(), size);
}

void ImComposer::Core::FontLoader::loadGlyphs(std::string name,
                                              std::string path, ImWchar min,
                                              ImWchar max, float size,
                                              float xOffset, float yOffset) {
  std::string fullPath = ImComposer::Utils::Bazel::getFullPath(
      ImComposer::Environment::applicationPath, path);

  static const ImWchar iconRange[] = {min, max, 0};
  ImFontConfig config;
  config.GlyphOffset = {xOffset, yOffset};

  auto& io = ImGui::GetIO();
  ImComposer::Core::FontLoader::fonts[name] =
      io.Fonts->AddFontFromFileTTF(fullPath.c_str(), size, &config, iconRange);
}
