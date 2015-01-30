#pragma once

#include "../core.h"
#include "../classes/application.h"

namespace guik {

Window* Application::win;

void Application::setWindow(Window* wnd) {
	win = wnd;
}

Window* Application::getWindow() {
	return win;
}

int Application::waitForEvents() {
	int result;

	__asm{
		push 10
		pop eax
		int 0x40
		mov result, eax
	}
	
	return result;
}

void Application::eventsHandler() {
	int k_event, i;

	Window* win = getWindow();

	while(k_event=waitForEvents()) {
		for (i=0;i<MAX_FORM_CONTROLS;i++) {
			if (win->getControl(i)) win->getControl(i)->sysevent(k_event);
		}

		switch (k_event) {
			case 1:
				win->draw();
			break;
			case 2:
				Byte keyCode;
				kos_GetKey(keyCode);
				win->setLastKeyCode(keyCode);
				//win->lastKeyPressCode = keyCode;
				//win->onKeyPress(keyCode);

				win->call(EVENT_KEY_PRESS);
			break;
			case 3:
				Dword buttonId;
				kos_GetButtonID(buttonId);
				
				win->setClickButtonId((int)buttonId);
			break;
		}
	}
}

void Application::run() {
	getWindow()->initialize();
	// Отрисовать окно
	getWindow()->draw();
	// Запустить ожидание событий

	eventsHandler();
}

void Application::Release() {
	delete win;
}

void Application::exit() {
	Release();
	__asm or eax, -1
	__asm int 0x40
}

}