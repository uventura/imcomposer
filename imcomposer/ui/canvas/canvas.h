#include "imcomposer/core/imgui/imgui.h"

namespace ImComposer
{
namespace UI
{
    class Canvas
    {
        public:
            Canvas();
            void draw();
        private:
            bool state_;
    };
}
}
