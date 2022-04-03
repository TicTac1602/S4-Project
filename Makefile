# Makefile
CC = gcc
CPPFLAGS=`pkg-config gtk+-3.0 --cflags`
CFLAGS = -Wall -Wextra -std=c99 -O2 -g 
LDLIBS = `pkg-config gtk+-3.0 --libs`


SRC = main.c glade/interface.c encode/encode.c data_encoding/encode_string.c data_encoding/polynomial.c data_encoding/final_struct.c data_encoding/makeqrcode.c data_encoding/qrmask.c

OBJ = ${SRC:.c=.o}
DEP = ${SRC:.c=.d}

all: main

main: ${OBJ} 

.PHONY: clean

clean:
	${RM} ${OBJ}   # remove object files
	${RM} ${DEP}   # remove dependency files
	${RM} main     # remove main program

# END

