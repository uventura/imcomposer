#include "imcomposer/core/imgui/imgui.h"

namespace ImComposer {
namespace UI {
class Menubar {
 public:
  Menubar();
  void begin();
  void setIconFont(ImFont* font);

 private:
  bool state_;
  ImFont* iconFont_;
};
}  // namespace UI
}  // namespace ImComposer
