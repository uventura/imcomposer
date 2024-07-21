#include "imcomposer/core/imgui/imgui.h"
#include "imcomposer/core/parser/json_widget_reader.h"

#include <memory>

namespace ImComposer
{
namespace UI
{
    class Canvas
    {
        public:
            Canvas(const std::string& widgetPath, const int id);
            void draw();
            const Core::Parser::JsonWidgetReader data();
            inline int id(){return id_;};
        private:
            bool state_;
            int id_{0};
            std::string widgetPath_;
            std::unique_ptr<Core::Parser::JsonWidgetReader> widgetInstance_;
    };
}
}
