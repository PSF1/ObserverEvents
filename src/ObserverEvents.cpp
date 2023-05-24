#include "ObserverEvents.h"

ObservableEvent::ObservableEvent() {
    this->id = "ObservableEvent";
}

void ObserverEvents::attachEventHandler(const ObservableEvent& event, std::function<void(const ObservableEvent&)> handler) {
    eventHandlers[event.id].push_back(handler);
}

void ObserverEvents::notifyEvent(const ObservableEvent& event) {
    if (eventHandlers.find(event.id) != eventHandlers.end()) {
        for (const auto& handler : eventHandlers[event.id]) {
            handler(event);
        }
    }
}
