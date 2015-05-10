#pragma once

#include "common.h"

#ifndef NULL
#define NULL 0
#endif

#ifdef RUN_ON_WINDOWS
	#include <iostream>
#else
	#include "stdlib.h"
	#include "stdio.h"
	#include "string.h"
	#include "kos32sys.h"
#endif

#include "classes/mstring.h"
#include "classes/mvector.h"
#include "functions/functions.h"

#include "controls/control.h"
#include "controls/label.h"
#include "controls/number.h"
#include "controls/button.h"
#include "controls/window.h"

#include "application.h"
