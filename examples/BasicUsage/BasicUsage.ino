#include <ObserverEvents.h>

ObserverEvents eventManager;

class ObservableEvent1 : public ObservableEvent {
  public:
    ObservableEvent1() {
      this->id = "ObservableEvent1";
    }
};

// Event 1 Handler
void evento1Handler(const ObservableEvent& event) {
  Serial.println("Event 1 fired");

  // ObservableEvent1 event1;
  //eventManager.notifyEvent(event1);
}

// Event 2 Handler
void evento2Handler(const ObservableEvent& event) {
  Serial.println("Event 2 fired");
}

void setup() {
  Serial.begin(115200);

  ObservableEvent event;
  eventManager.attachEventHandler(event, evento1Handler);

  ObservableEvent1 event1;
  eventManager.attachEventHandler(event1, evento2Handler);
}

void loop() {
  ObservableEvent event;
  eventManager.notifyEvent(event);
  delay(3000);
}
