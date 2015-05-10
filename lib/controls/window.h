#pragma once

#include "control.h"
#include "../classes/mstring.h"
#include "../functions/functions.h"
#include "kos32sys.h"


namespace guik {

class Window : public Control {
public:
	Window();
	virtual ~Window();

	virtual void init();
	virtual void destroy();
	virtual void draw(bool relative=true);

	virtual void setStyle(int style);
	virtual int getStyle();

	virtual void setTitle(const char* Title);
	virtual const char* getTitle();

    // События для окна
    static const int EVENT_KEY = 4;
    virtual void onSysEvent(int event);

    static int getLastKeyCode();
    static void setLastKeyCode(int keyCode);
    static void clearLastKeyCode();
    static int getKeyCode();

	Color color;
protected:
	mstring title;
	int style;

	static oskey_t lastKey;
};

}
