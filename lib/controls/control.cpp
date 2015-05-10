#include "control.h"
#include "../functions/functions.h"
#include "../classes/mvector.h"

guik::Control::Control() : x(0), y(0), sizeX(0), sizeY(0), visible(true) {
	parent = 0;
}

guik::Control::~Control() {
	if (parent) {
		//delete parent;
		parent = 0;
	}
}

void guik::Control::init() {
	this->callEvent(Control::EVENT_INIT);

	for (int i=0;i<childs.getSize();i++) {
		if (childs[i]) childs[i]->callEvent(Control::EVENT_INIT);
	}
}

void guik::Control::destroy() {
	this->callEvent(Control::EVENT_DESTROY);

	for (int i=0;i<childs.getSize();i++) {
		if (childs[i]) childs[i]->callEvent(Control::EVENT_DESTROY);
	}
}

void guik::Control::callEvent(int event) {
	this->onEvent(event);

	for (int i=0;i<childs.getSize();i++) {
		if (childs[i]) childs[i]->callEvent(event);
	}
}

void guik::Control::setParent(guik::Control* parent) {
	this->parent = parent;
}

void guik::Control::onEvent(int event) {

}

void guik::Control::draw(bool relative) {
    /**guik::mstring str;
    str = "Draw element ";
    str += this->name;
    str += "; X: ";

    char* buffer;
    char* buffer2;

    str += guik::itoa(this->x, buffer, 10);
    str += ", Y: ";
    str += guik::itoa(this->y, buffer2, 10);
    str += ";\n";

    debug(str);*/

    if (this->visible) {
        for (int i=0;i<childs.getSize();i++) {
            int child_pos_x = childs[i]->getPositionX();
            int child_pos_y = childs[i]->getPositionX();

            // Относительное позиционирование
            if (relative) childs[i]->setPosition(this->x+child_pos_x, this->y+child_pos_y);
            childs[i]->draw();
            if (relative) childs[i]->setPosition(child_pos_x, child_pos_y);
        }
    }

	this->callEvent(Control::EVENT_DRAW);
}

void guik::Control::setPosition(int x, int y) {
	this->x = x;
	this->y = y;
}

int guik::Control::getPositionX() {
	return this->x;
}

int guik::Control::getPositionY() {
	return this->y;
}

void guik::Control::setSize(int sizeX, int sizeY) {
	this->sizeX = sizeX;
	this->sizeY = sizeY;
}

int guik::Control::getSizeX() {
	return this->sizeX;
}

int guik::Control::getSizeY() {
	return this->sizeY;
}

void guik::Control::setVisible(bool visible) {
	this->visible = visible;
}

bool guik::Control::isVisible() {
	return this->visible;
}

void guik::Control::setId(int id) {
	this->id = id;
}

int guik::Control::getId() {
	return this->id;
}

void guik::Control::addChild(guik::Control* child) {
	child->setParent(this);
	this->childs.push(child);
}

void guik::Control::callSysEvent(int event) {
    this->onSysEvent(event);

	for (int i=0;i<childs.getSize();i++) {
		this->childs[i]->onSysEvent(event);
	}
}

void guik::Control::onSysEvent(int event, int param1, int param2) {

}

void guik::Control::onSysEvent(int event) {

}

void guik::Control::setName(const char* name) {
    this->name = name;
}

const char* guik::Control::getName() {
    return this->name.getString();
}

guik::Control* guik::Control::getChildByName(guik::mstring Name) {
	for (int i=0;i<childs.getSize();i++) {
        if (this->childs[i]->name == Name) {
            return this->childs[i];
        }
        else {
            this->childs[i]->getChildByName(Name);
        }
	}

	return 0;
}

guik::Control* guik::Control::getChildById(int id) {
	for (int i=0;i<childs.getSize();i++) {
        if (this->childs[i]->id == id) {
            return this->childs[i];
        }
        else {
            this->childs[i]->getChildById(id);
        }
	}

	return 0;
}
