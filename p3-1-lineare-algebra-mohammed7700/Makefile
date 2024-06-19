BIN=linalg
CFFLAGS = -Wall -g

all: linalg

linalg: main.o	io.o pointmath.o
	gcc $(CFFLAGS) -o linalg main.o io.o pointmath.o 

main.o: main.c io.h point.h pointmath.h
	gcc $(CFFLAGS) -c main.c

io.o: io.c debug.h io.h
	gcc $(CFFLAGS) -c io.c

pointmath.o: pointmath.c pointmath.h
	gcc $(CFFLAGS) -c pointmath.c

clean:
	rm -f main.o pointmath.o io.o
	rm -f ${BIN}
