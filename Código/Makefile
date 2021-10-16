all: OrderedPair.o
	gcc closest.c OrderedPair.o -o closest -lm

OrderedPair.o: OrderedPair.c
	gcc -g -o OrderedPair.o -c OrderedPair.c -lm

clean:
	rm -f closest.c;

