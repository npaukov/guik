#pragma once

#include "control.h"
#include "../classes/mstring.h"

namespace guik {

template <typename T>
class Number : public Control {
public:
	Number();
	virtual ~Number();

	virtual void init();
	virtual void destroy();
	virtual void draw(bool relative=true);

	Color backgroundColor;
	Color textColor;

	virtual void setNumber(T number);
	virtual T getNumber();

protected:
    T number;
};

}
