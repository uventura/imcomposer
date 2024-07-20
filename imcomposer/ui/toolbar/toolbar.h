#include "imcomposer/core/imgui/imgui.h"
#include "imcomposer/events/events.h"

namespace ImComposer
{
namespace UI
{
    class Toolbar
    {
        public:
            Toolbar();
            ImComposer::Event draw();
        private:
            bool state_;
    };
}
}
