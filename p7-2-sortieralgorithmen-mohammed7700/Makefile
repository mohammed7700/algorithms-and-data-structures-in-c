CC=gcc
CFLAGS=-Wall -Werror -O2

OBJECTS=main.o io.o quicksort.o mergesort.o selectionsort.o insertionsort.o

all: sortme randnums

io.o: io.h
quicksort.o: quicksort.h
mergesort.o: mergesort.h
selectionsort.o: selectionsort.h
insertionsort.o: insertionsort.h
main.o: io.h quicksort.h

sortme: ${OBJECTS}
	${CC} ${CFLAGS} -o sortme ${OBJECTS}

randnums: randnums.o
	${CC} ${CFLAGS} -o randnums randnums.o

clean:
	rm -f sortme
	rm -f ${OBJECTS}
	rm -f randnums.o
	rm -f randnums


.PHONY: all clean
