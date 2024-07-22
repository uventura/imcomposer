#include "imcomposer/core/imgui/imgui.h"
#include "imcomposer/events/events.h"
#include "imcomposer/core/parser/json_widget_reader.h"

namespace ImComposer
{
namespace UI
{
    class Properties
    {
        public:
            Properties();
            ImComposer::Event draw();

            // The pointer usage is bad, probably should be replaced by a shared pointer.
            // Or somthing better.
            void setWidgetData(ImComposer::Core::Parser::JsonWidgetReader* widgetData);
        private:
            bool propertyExists_{false};
            ImComposer::Core::Parser::JsonWidgetReader* widgetData_;
    };
}
}
