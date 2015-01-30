#pragma once

namespace guik {

class Window : public Control {
public:
	Window(char* header="My Window", int sizeX=300, int sizeY=200, int x=0, int y=0);
	~Window();

	// Системные функции для окна
	void update();
	void draw(bool flagUpdate);
	void draw();
	void drawControls();
	void initializeControls();

	// Методы для получения элементов (костыли)
	Button* getButton(int);
	Control* getControl(int id);
	// Методы для регистрации элементов

	int addControl(Control*);


	virtual void onKeyPress(int keyCode) {};
	virtual void initialize() {};

	void setX(int x);
	int getX();
	void setY(int y);
	int getY();

	void setSizeX(int size);
	int getSizeX();
	void setSizeY(int size);
	int getSizeY();

	void setAreaType(int type);
	int getAreaType();
	void setAreaColor(int color);
	int getAreaColor();

	void setHeaderType(int type);
	int getHeaderType();
	void setHeaderColor(int color);
	int getHeaderColor();

	void setHeaderText(char* text);
	const char* getHeaderText();

	void setLastKeyCode(int code);
	int getLastKeyCode();

	void setClickButtonId(int id);
	int getClickButtonId();

protected:
	Word x,y,sizeX,sizeY;
	Byte mainAreaType;
	Dword mainAreaColour;
	Byte headerType;
	Dword headerColour;
	char* header;

	Control* controls[MAX_FORM_CONTROLS];
	int lastControlId;

	Byte lastKeyPressCode;
	int clickButtonId;

	bool isInitialized;
};

}