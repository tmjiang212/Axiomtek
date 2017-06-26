_VERSION:=$(shell uname -r | cut -c1-3 | sed 's/2\.[56]/2\.6/')
LBITS := $(shell getconf LONG_BIT)
param_64 :=
ifeq ($(LBITS),64)
  lib_dir32_64=64
  param_64 := -fPIC
  ifeq "$(wildcard $(LIB_PATH))" ""
        LIB_PATH=/usr/lib/
  else
        LIB_PATH=/usr/lib64/
  endif
else
   LIB_PATH=/usr/lib/
  lib_dir32_64=32
endif

ifeq ($(K_VERSION), 2.4)
  lib_dir := 2.4.x
else
  lib_dir := 2.6.x
endif

all: hwm wdt dio comport

# Compiler
CC = cc

# Include files

# libs
LIB = axio 

# Include libs
INCLUDE_LIB = $(LIB_PATH)

# Options for development
CFLAGS = -Wall

hwm:hwm.c
	$(CC) $(CFLAGS) -o hwm hwm.c -l$(LIB) -L$(INCLUDE_LIB)

wdt:wdt.c
	$(CC) $(CFLAGS) -o wdt wdt.c -l$(LIB) -L$(INCLUDE_LIB)

dio:dio.c
	$(CC) $(CFLAGS) -o dio dio.c -l$(LIB) -L$(INCLUDE_LIB)

comport:comport.c
	$(CC) $(CFLAGS) -o comport comport.c
	
clean:
	rm -f hwm wdt dio comport
