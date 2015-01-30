#pragma once

namespace guik {

class EventAction {
public:
	int type;
	//Stack<void (*)()> handlers; 
	void (*handlers[30])();
	int lastHandlerId;

	EventAction();
	void add(void (*handler)());
};

class Event {
public:
	//void (*handlers[100])();
	EventAction* actions[30];
	
	int lastEventType;

	void addHandler(int action, void (*handler)());
	void call(int action);
};

}