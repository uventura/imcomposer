#pragma once

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
            Toolbar toolbar_;
    };
}
}
