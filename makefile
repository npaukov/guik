EXEC = main

LIB_SOURCE = lib/application.o lib/kos2win.o 
FUNCTIONS_SOURCE = lib/functions/functions.o
CLASSES_SOURCE = lib/classes/mstring.o
CONTROLS_SOURCE = lib/controls/control.o lib/controls/label.o lib/controls/number.o lib/controls/button.o lib/controls/window.o

SOURCE = $(LIB_SOURCE) $(FUNCTIONS_SOURCE) $(CLASSES_SOURCE) $(CONTROLS_SOURCE)

CC = kos32-gcc
LD = kos32-ld
OBJCOPY = kos32-objcopy

SDK_DIR:= /d/kolibri/contrib/sdk
LDFLAGS = -static -S -nostdlib -T$(SDK_DIR)/sources/newlib/app.lds -Map $(EXEC).map --image-base 0
CFLAGS = -c -O2 -fomit-frame-pointer -U__WIN32__ -U_Win32 -U_WIN32 -U__MINGW32__ -UWIN32

INCLUDES= -I$(SDK_DIR)/sources/newlib/libc/include
LIBPATH:= -L$(SDK_DIR)/lib -L/home/autobuild/tools/win32/mingw32/lib

export PATH=$PATH:/home/autobuild/tools/win32/bin:/MinGW/bin

default: $(EXEC)
	
clean:

$(EXEC): $(SOURCE) $(EXEC).o makefile
		#$(LD) $(LDFLAGS) $(LIBPATH) -o $(EXEC) *.o -lgcc -lapp -lc.dll
		$(LD) $(LDFLAGS) $(LIBPATH) -o $(EXEC) *.o $(SOURCE) -lapp -lsupc++ -lgcc_eh -lc.dll -lgcc 
		$(OBJCOPY) $(EXEC) -O binary

%.o : %.cpp makefile
		$(CC) $(CFLAGS) $(INCLUDES) -o $@ $<