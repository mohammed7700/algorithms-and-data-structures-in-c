CFFLAGS = -Wall -g

all:primes

primes: main.o primes.o
	gcc $(CFFLAGS) -o primes main.o primes.o

main.o: main.c primes.h
	gcc $(CFFLAGS) -c main.c

primes.o: primes.c
	gcc $(CFFLAGS) -c primes.c

clean:
	rm -f primes.o main.o
	rm -f primes
