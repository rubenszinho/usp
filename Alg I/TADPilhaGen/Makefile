all: pilha.o main.o
	gcc -o jogoDeCartas pilha.o main.o

run: jogoDeCartas
	./jogoDeCartas

pilha.o: pilha.c pilha.h
	gcc -c pilha.c

main.o: main.c pilha.h
	gcc -c main.c

clean:
	rm *.o jogoDeCartas