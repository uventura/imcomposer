#include "imcomposer/core/imgui/imgui.h"

namespace ImComposer
{
namespace UI
{
    class Canvas
    {
        public:
            Canvas(const std::string& widgetPath);
            void draw();
        private:
            bool state_;
            std::string widgetPath_;
    };
}
}
