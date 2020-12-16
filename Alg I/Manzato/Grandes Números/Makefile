all: trab6

trab6: list.o list.h bignum.o bignum.h main.o
	gcc list.o bignum.o main.o -o trab6

list.o: list.c
	gcc -c -g -Wall list.c

bignum.o: bignum.c
	gcc -c -g -Wall bignum.c

main.o: main.c
	gcc -c -g -Wall main.c

clean:
	rm *.o
run: trab6
	./trab6
