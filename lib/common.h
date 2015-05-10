#pragma once

#ifndef RUN_ON_WINDOWS
//#define RUN_ON_WINDOWS 1
#endif

#ifdef RUN_ON_WINDOWS
#include "kos2win.h"
#else
	#include "kos32sys.h"
#endif