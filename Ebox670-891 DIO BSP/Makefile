#Install Library in /usr/lib for kernel 2.4.x
K_VERSION:=$(shell uname -r | cut -c1-3 | sed 's/2\.[56]/2\.6/')

LBITS := $(shell getconf LONG_BIT)
LIB_PATH=/usr/lib64/
ifeq ($(LBITS),64)
  lib_dir32_64=64
  ifeq "$(wildcard $(LIB_PATH))" ""
        LIB_PATH=/usr/lib/
  else
        LIB_PATH=/usr/lib64/
  endif
else
   LIB_PATH=/usr/lib/
  lib_dir32_64=32
endif


all:
	cp ./lib/$(lib_dir32_64)/libaxio.so.1.0.0 /usr/lib/ ; \
	cd /usr/lib ; \
	ln -s libaxio.so.1.0.0 libaxio.so.0 ; \
	ln -s libaxio.so.0 libaxio.so

clean:
	cd /usr/lib ; \
	rm -f libaxio.*
