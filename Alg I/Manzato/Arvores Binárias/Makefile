all: main

run: main
	./main

main: main.o arvore.o
	gcc -Wall -o main main.o arvore.o

main.o: main.c arvore.h
	gcc -Wall -c main.c arvore.h

arvore.o: arvore.c arvore.h
	gcc -Wall -c arvore.c arvore.h
