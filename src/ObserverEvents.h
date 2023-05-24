/**
 ObserverEvents
 
 Arduino IDE event manager implementing Observer Desing Pattern.
 
 Author: Pedro Pelaez <aaaaa976@gmail.com>
 Generated with assitence of ChatGPT by OpenAI.
 
 Released into Attribution-ShareAlike 4.0 International CC BY-SA
 Licence: https://creativecommons.org/licenses/by-sa/4.0/legalcode
 */

#ifndef OBSERVEREVENTS_H
#define OBSERVEREVENTS_H

#include <map>
#include <vector>
#include <functional>
#include <string>

class ObservableEvent {
public:
  std::string id;

  ObservableEvent();
};

class ObserverEvents {
private:
  std::map<std::string, std::vector<std::function<void(const ObservableEvent&)>>> eventHandlers;

public:
  void attachEventHandler(const ObservableEvent& event, std::function<void(const ObservableEvent&)> handler);
  void notifyEvent(const ObservableEvent& event);
};

#endif // OBSERVEREVENTS_H
