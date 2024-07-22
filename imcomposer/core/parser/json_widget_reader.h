#pragma once

#include <string>

#include <nlohmann/json.hpp>
using json = nlohmann::json;

namespace ImComposer {
    namespace Core
    {
        namespace Parser {
            class JsonWidgetReader {
                public:
                    JsonWidgetReader(const std::string& location);
                    void draw();

                    inline const std::string title();
                    inline const unsigned int width();
                    inline const unsigned int height();

                    inline bool selectedItemExists();
                    json currentSelectedItem();

                private:
                    json widgetParsed_;
                    json selectedItem_;
                    bool selectedItemExists_{false};

                    std::string title_;
                    unsigned int width_, height_;

                    void beginElement(const json& element);
                    void endElement(const json& element);
            };
        }
    }
}

const std::string ImComposer::Core::Parser::JsonWidgetReader::title() {
    return title_;
}

const unsigned int ImComposer::Core::Parser::JsonWidgetReader::width() {
    return width_;
}

const unsigned int ImComposer::Core::Parser::JsonWidgetReader::height() {
    return height_;
}