#include "../core.h"
#include "../classes/events.h"

#include "../modules/window.h"
#include "../classes/draw.h"
namespace guik {

void Window::setX(int x) {
	this->x = x;
}

int Window::getX() {
	return this->x;
}

void Window::setY(int y) {
	this->y = y;
}

int Window::getY() {
	return this->y;	
}


void Window::setSizeX(int size) {
	this->sizeX = size;
}

int Window::getSizeX() {
	return this->sizeX;
}

void Window::setSizeY(int size) {
	this->sizeY = size;
}

int Window::getSizeY() {
	return this->sizeY;	
}

void Window::setAreaType(int type) {
	this->mainAreaType = type;
}

int Window::getAreaType() {
	return this->mainAreaType;
}

void Window::setAreaColor(int color) {
	this->mainAreaColour = color;
}

int Window::getAreaColor() {
	return this->mainAreaColour;
}

void Window::setHeaderType(int type) {
	this->headerType = type;
}

int Window::getHeaderType() {
	return this->headerType;
}

void Window::setHeaderColor(int color) {
	this->headerColour = color;
}

int Window::getHeaderColor() {
	return this->headerColour;
}

void Window::setLastKeyCode(int code) {
	this->lastKeyPressCode = code;
	this->onKeyPress(code);
}

int Window::getLastKeyCode() {
	return this->lastKeyPressCode;
}

void Window::setClickButtonId(int id) {
	this->clickButtonId = id;

	Button* button = this->getButton(id);
	if (button) {
		button->call(EVENT_BUTTON_CLICK);
		button->onClick();
	}

	if (id == 1) {
		this->call(EVENT_WINDOW_CLOSE);
		return Application::exit();
	}
}

int Window::getClickButtonId() {
	return this->clickButtonId;
}

void Window::setHeaderText(char* text) {

}

const char* Window::getHeaderText() {
	return this->header;
}

Control* Window::getControl(int id) {
	if (id >= MAX_FORM_CONTROLS) return NULL;

	if (!controls[id]) return NULL;
	return controls[id];
}

void Window::update() {
	draw(false);
}

void Window::draw() {
	draw(false);
}

void Window::draw(bool flagUpdate) {
	if (flagUpdate) kos_WindowRedrawStatus(1);

	Draw::window(x,y,sizeX,sizeY, mainAreaType,mainAreaColour,headerType,headerColour,(Dword)header);

	int i = 0;

	for (i=0;i<MAX_FORM_CONTROLS;i++) {
		if (controls[i]) {
			controls[i]->draw();
			controls[i]->onDraw();
		}
	}

	this->call(EVENT_DRAW);

	if (flagUpdate) kos_WindowRedrawStatus(2);
}

void Window::initializeControls() {
	if (!isInitialized) {
		int i;
		for (i=0;i<MAX_FORM_CONTROLS;i++) {
			controls[i]->initialize();
		}

		isInitialized = true;
	}
}

Window::Window(char* header, int sizeX, int sizeY, int x, int y) : x(x),y(y),sizeX(sizeX),sizeY(sizeY),
				mainAreaType(0x33), mainAreaColour(COLOR_WHITE), headerType(0), headerColour(COLOR_BLACK), header(header), lastControlId(0), isInitialized(false)
{

}

Window::~Window() {
	int i;
	for (i=0;i<MAX_FORM_CONTROLS;i++) {
		delete controls[i];
	}
}

Button* Window::getButton(int id) {
	int i;
	for (i=0;i<MAX_FORM_CONTROLS;i++) {
		if (controls[i]->getType() == CONTROL_BUTTON && ((Button*)controls[i])->getId() == id) return (Button*)controls[i];
	}

	return 0;
}

int Window::addControl(Control* control) {
	controls[lastControlId] = control;

	control->setElementId(lastControlId);
	control->initialize();

	lastControlId++;
	return (lastControlId-1);
}

}