
all: dio dio_0x0F 

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

dio_0x0F: dio_0x0F.c
	$(CC) $(CFLAGS) -o dio_0x0F dio_0x0F.c -l$(LIB) -L$(INCLUDE_LIB)	

clean:
	rm -f dio dio_0x0F
