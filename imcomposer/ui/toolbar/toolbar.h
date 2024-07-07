#include "imcomposer/core/imgui/imgui.h"

namespace ImComposer
{
namespace UI
{
    class Toolbar
    {
        public:
            Toolbar();
            void draw();
        private:
            bool state_;
    };
}
}
