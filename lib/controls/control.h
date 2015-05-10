#pragma once

#include "../classes/mstring.h"
#include "../classes/mvector.h"

namespace guik {
class Control {
public:
    Control();
    virtual ~Control();

	virtual void addChild(Control* child);

	virtual void setParent(Control* parent);

	virtual void init();
	virtual void destroy();
	virtual void draw(bool relative = true);

	virtual void onEvent(int event);
	virtual void onSysEvent(int event, int param1, int param2);
	virtual void onSysEvent(int event);

	virtual void callEvent(int event);
	virtual void callSysEvent(int event);

	// Стандартные события для любого элемента
	static const int EVENT_DESTROY = 0;
	static const int EVENT_INIT = 1;
	static const int EVENT_DRAW = 2;

	// Позиция элемента
	virtual void setPosition(int x, int y);
	virtual int getPositionX();
	virtual int getPositionY();

	virtual void setSize(int sizeX, int sizeY);
	virtual int getSizeX();
	virtual int getSizeY();

	virtual void setVisible(bool visible);
	virtual bool isVisible();

	virtual void setId(int id);
	virtual int getId();

    virtual void setName(const char* name);
    virtual const char* getName();

    virtual Control* getChildByName(guik::mstring Name);
    virtual Control* getChildById(int id);

protected:
	Control* parent;

	mvector<Control*> childs;

	int x, y; // Координаты элемента
	int sizeX, sizeY; // Размеры элемета
	bool visible; // Флаг видимости

	int id; // ID элемента

	// Уникальное строковое имя элемента
	mstring name;
};
}
