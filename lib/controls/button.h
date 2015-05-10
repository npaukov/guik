#pragma once

#include "control.h"
#include "../classes/mstring.h"
#include "../functions/functions.h"

namespace guik {

class Button : public Control {
public:
	Button();
	virtual ~Button();

	virtual void init();
	virtual void destroy();
	virtual void draw(bool relative=true);

    // События для кнопки
    static const int EVENT_CLICK = 20;
    virtual void onSysEvent(int event);

    static int getLastButtonCode();
    static void setLastButtonCode(int buttonCode);
    static void clearLastButtonCode();
    static int getButtonCode();

	mstring text;
	Color backgroundColor;
	Color textColor;
protected:
    static int lastButtonCode;
};

}
