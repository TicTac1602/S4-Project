# Makefile
CC = gcc
CFLAGS =-Wall -Wextra -Werror -std=c99 -O2 -g

SRC = test.c encode_string.c
OBJ = ${SRC:.c=.o}
DEP = ${SRC:.c=.d}

all: test 

test: ${OBJ}

.PHONY: clean

clean:
	${RM} ${OBJ}   # remove object files
	${RM} ${DEP}   # remove dependency files
	${RM} test     # remove main program

-include ${DEP}

# END
