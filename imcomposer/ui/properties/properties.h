#include "imcomposer/core/imgui/imgui.h"

namespace ImComposer
{
namespace UI
{
    class Properties
    {
        public:
            Properties();
            void draw();
        private:
            bool state_;
    };
}
}
