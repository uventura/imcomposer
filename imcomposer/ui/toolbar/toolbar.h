#include "imcomposer/core/imgui/imgui.h"

namespace ImComposer
{
namespace UI
{
    class Toolbar
    {
        public:
            Toolbar();
            void begin();
            void setIconFont(ImFont* font);
        private:
            bool state_;
            ImFont* iconFont_;
    };
}
}
