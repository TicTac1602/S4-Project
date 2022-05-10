#Makefile

CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -O2
LDFLAGS = -fsanitize=address -lm
#LDFLAGS = -lm

SRC = patterns.c decode.c colors.c

OBJ = ${SRC:.c=.o}
DEP = ${SRC:.c=.d}

all: decode

decode: ${OBJ}

.PHONY: clean

clean:
	${RM} ${OBJ} # remove .o files
	${RM} ${DEP} # remove .d files
	${RM} decode # remove executable

# END

