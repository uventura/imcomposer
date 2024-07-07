#pragma once

#include "imcomposer/ui/menubar/menubar.h"
#include "imcomposer/ui/toolbar/toolbar.h"

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
            Toolbar toolbar_;
    };
}
}
