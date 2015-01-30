#pragma once

#include "../core.h"
#include "../classes/events.h"
namespace guik {

EventAction::EventAction() {
	lastHandlerId = 0;
}

void EventAction::add(void (*handler)()) {
	handlers[lastHandlerId] = handler;
	lastHandlerId++;
}

void Event::addHandler(int action, void (*handler)()) {
	if (actions[action] == NULL) {
		actions[action] = new EventAction;
	}

	actions[action]->add(handler);
}

void Event::call(int action) {
	if (actions[action] == NULL) return;
	int i;
	//void (*hnd)();

	for (i=0;i<30;i++) {
		if (actions[action]->handlers[i]) actions[action]->handlers[i]();
		//if (hnd != NULL) hnd();
    }
}

}