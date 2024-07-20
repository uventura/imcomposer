#include "imcomposer/core/imgui/imgui.h"
#include "imcomposer/events/events.h"

namespace ImComposer
{
namespace UI
{
    class Properties
    {
        public:
            Properties();
            ImComposer::Event draw();
        private:
            bool state_;
    };
}
}
