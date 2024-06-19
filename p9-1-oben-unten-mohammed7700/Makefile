CC=gcc
CFLAGS=-Wall -Werror -g
OBJECTS=treemain.o bintree.o

all: levels

treemain.o: bintree.h
bintree.o: bintree.h

levels: ${OBJECTS}
	${CC} ${CFLAGS} -o levels ${OBJECTS}

clean:
	rm -f levels
	rm -f ${OBJECTS}

.PHONY: clean all
