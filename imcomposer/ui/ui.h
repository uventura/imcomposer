#pragma once

#include "imcomposer/ui/menubar/menubar.h"
#include "imcomposer/ui/toolbar/toolbar.h"
#include "imcomposer/ui/canvas/canvas.h"
#include "imcomposer/ui/properties/properties.h"
#include "imcomposer/core/file_dialog/file_dialog.h"
#include "imcomposer/events/events.h"

#include <memory>
#include <vector>

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
            Properties properties_;

            std::vector<std::unique_ptr<Canvas>> openedCanvas_;

        private:
            void eventChecker(ImComposer::Event event);
            void eventAction();
            void drawCanvas();

            void fileEvent(ImComposer::EventActionValue eventAction);
        
        private:
            Core::FileDialog file_;
    };
}
}
