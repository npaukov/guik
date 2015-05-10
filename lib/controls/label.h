#pragma once

#include "control.h"
#include "../classes/mstring.h"

namespace guik {

class Label : public Control {
public:
	Label();
	virtual ~Label();

	virtual void init();
	virtual void destroy();
	virtual void draw(bool relative=true);

	Color backgroundColor;
	Color textColor;

	virtual void setText(const char* text);
	virtual const char* getText();

protected:
    mstring text;
};

}
