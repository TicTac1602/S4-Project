# Makefile
CC = gcc
CFLAGS = `pkg-config --cflags gtk+-3.0` -Wall -Wextra -std=c99 -O2 -g

SRC = test.c encode_string.c
OBJ = ${SRC:.c=.o}
DEP = ${SRC:.c=.d}

all: main

main: ${OBJ}

.PHONY: clean

clean:
	${RM} ${OBJ}   # remove object files
	${RM} ${DEP}   # remove dependency files
	${RM} main     # remove main program

-include ${DEP}

# END