
all: dio 

# Compiler
CC = cc

# Include files
INCLUDE = .

# libs
LIB = axio

# Include libs
INCLUDE_LIB = /usr/lib

# Options for development
CFLAGS = -Wall

	
dio: dio.c
	$(CC) $(CFLAGS) -o dio dio.c -l$(LIB) -L$(INCLUDE_LIB)	


clean:
	rm -f dio
