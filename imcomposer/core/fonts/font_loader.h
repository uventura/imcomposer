#ifndef IMCOMPOSER_CORE_FONT_LOADER
#define IMCOMPOSER_CORE_FONT_LOADER

#include <string>
#include <map>

#include "imgui.h"

namespace ImComposer
{
namespace Core
{
    class FontLoader
    {
        private:
            void loadFont(std::string name, std::string path, float size);
            void loadGlyphs(std::string name, std::string path, ImWchar min, ImWchar max, float size, float xOffset, float yOffset);
        public:
            void load();

            static std::map<std::string, ImFont*> fonts;
            // static inline ImFont* getFont(std::string fontName){return fonts_[fontName];};
    };
}
}

#endif
