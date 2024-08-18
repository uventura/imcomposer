#pragma once

#include "imcomposer/events/file_events.h"
#include "imcomposer/events/none_events.h"

namespace ImComposer {
enum class EventType {
  None,
  FileEvent,
  WidgetEvent,
};

// Why this an integer?
// Because using an integer is possible
// to create several enums and at the same
// time they don't need to be part of the
// same enum. Unfortunatelly, there is no
// inheritance for enums, so it's not possible
// to create a generic enum and change it for
// different usages.
typedef int EventActionValue;

struct Event {
  EventType type{EventType::None};
  EventActionValue event{EventAction::None::None};
};
}  // namespace ImComposer