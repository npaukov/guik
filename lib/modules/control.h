#pragma once

namespace guik {

class Control : public Event {
public:
	Control* parent;

	virtual void draw(){};
	virtual void initialize() {return;};
	virtual void onDraw(){};
	virtual Control* setParent(Control* parent) {this->parent = parent; return this;};
	virtual int getType() {return CONTROL_UNKNOWN;};
	//virtual int getId() {return 0;};
	virtual void sysevent(int eventCode){};

	virtual void setElementId(int id) {
		this->elementId = id;
	};

	virtual int getElementId() {
		return this->elementId;
	};
protected:
	int elementId;
};

}