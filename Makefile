.POSIX:

#
# COMPILE OPTIONS
#

CC=c99

CFLAGS=-Wall -Wextra -Werror -pedantic -std=c99

INC=-I.

LIBS=-L.

# SRCS

SRC=examples/main.c

# OBJS

OBJ=$(SRC:.c=.o)

# TARGETS

TARGET=program

.PHONY: test

${TARGET}: ${OBJ}
	${CC} ${SRC} -o ${TARGET} ${CFLAGS} ${INC}

.SUFFIX: .c .o

.c.o:
	${CC} -c ${CFLAGS} $< -o $@ ${INC}

test: ${TARGET}
	-./${TARGET}

.SILENT: clean

clean:
	rm -vf ${TARGET} ${OBJ}
