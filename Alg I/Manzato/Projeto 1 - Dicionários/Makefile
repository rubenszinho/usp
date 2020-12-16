all: proj1

proj1: dict.o operacoes.o main.o
	gcc dict.o operacoes.o main.o -o proj1

dict.o: dict.c
	gcc -c -g -Wall dict.c

operacoes.o: operacoes.c
	gcc -c -g -Wall operacoes.c

main.o: main.c
	gcc -c -g -Wall main.c

clean:
	rm *.o
run: proj1
	./proj1
