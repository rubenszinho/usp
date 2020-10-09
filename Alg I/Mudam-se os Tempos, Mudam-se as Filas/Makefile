all: fila.o main.o
	gcc -o  MudamAsFilas fila.o main.o

run: MudamAsFilas
	./MudamAsFilas

fila.o: fila.c fila.h
	gcc -c fila.c

main.o: main.c fila.h
	gcc -c main.c

clean:
	rm *.o MudamAsFilas