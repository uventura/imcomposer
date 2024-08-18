#include "imcomposer/core/imgui/imgui.h"
#include "imcomposer/core/parser/json_widget_reader.h"

#include <memory>

#include <nlohmann/json.hpp>
using json = nlohmann::json;

namespace ImComposer
{
namespace UI
{
    class Canvas
    {
        public:
            Canvas(const std::string& widgetPath, const int id);
            void draw();

            inline int id(){return id_;};
            inline json& widget(){return widgetInstance_->widget();};

        private:
            bool state_;
            int id_{0};
            std::string widgetPath_;
            std::unique_ptr<Core::Parser::JsonWidgetReader> widgetInstance_;
    };
}
}
