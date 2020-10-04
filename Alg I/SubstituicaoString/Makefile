all: main

run: main
	./main
main: main.o funcao.o
	gcc -g -o main main.o funcao.o

main.o: main.c funcao.h
	gcc -g -c main.c funcao.h

funcao.o: funcao.c funcao.h
	gcc -g -c funcao.c funcao.h
clean:
	rm *.o
