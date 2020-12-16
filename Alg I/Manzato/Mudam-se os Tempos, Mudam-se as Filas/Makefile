all: MudamAsFilas

run: MudamAsFilas
	./MudamAsFilas

MudamAsFilas: fila.o main.o
	gcc -g -Wextra -Wall -o  MudamAsFilas fila.o main.o

fila.o: fila.c fila.h
	gcc -g -Wextra -Wall -c fila.c

main.o: main.c fila.h
	gcc -g -Wextra -Wall -c main.c

clean:
	rm *.o MudamAsFilas
