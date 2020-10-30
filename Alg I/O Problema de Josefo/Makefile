all: OProblemaDeJosefo

run: OProblemaDeJosefo
	./OProblemaDeJosefo

OProblemaDeJosefo: lista.o main.o
	gcc -g -Wextra -Wall -o  OProblemaDeJosefo lista.o main.o

lista.o: lista.c lista.h
	gcc -g -Wextra -Wall -c lista.c

main.o: main.c lista.h
	gcc -g -Wextra -Wall -c main.c

clean:
	rm *.o OProblemaDeJosefo
