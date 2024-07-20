#include "imcomposer/ui/ui.h"
#include "imcomposer/core/imgui/imgui.h"
#include "imcomposer/core/fonts/fonts.h"
#include "imcomposer/events/events.h"

#include <iostream>

ImComposer::UI::MainUi::MainUi() {}

void ImComposer::UI::MainUi::draw() {
    menubar_.begin();

    static ImComposer::Event event;

    event = toolbar_.draw();
    eventChecker(event);

    for(int i = 0; i < openedCanvas_.size(); ++i) {
        openedCanvas_[i].get()->draw();
    }

    event = properties_.draw();

    eventAction();
}

void ImComposer::UI::MainUi::eventChecker(ImComposer::Event event) {
    switch(event.type) {
        case ImComposer::EventType::None:
            break;
        case ImComposer::EventType::FileEvent:
            fileEvent(event.event);
            break;
        case ImComposer::EventType::WidgetEvent:
            break;
    }
}

void ImComposer::UI::MainUi::eventAction() {
    if(file_.isReady()) {
        openedCanvas_.push_back(std::make_unique<Canvas>(file_.getValue()));
        file_.reset();
    }
}

void ImComposer::UI::MainUi::fileEvent(ImComposer::EventActionValue eventAction) {
    if(eventAction == ImComposer::EventAction::File::Open) {
        file_.openFile();
    }
}