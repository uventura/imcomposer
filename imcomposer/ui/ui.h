#pragma once

#include "imcomposer/ui/menubar/menubar.h"

namespace ImComposer
{
namespace UI
{
    class MainUi
    {
        public:
            MainUi();
            void draw();
        private:
            bool state_;
            Menubar menubar_;
    };
}
}
