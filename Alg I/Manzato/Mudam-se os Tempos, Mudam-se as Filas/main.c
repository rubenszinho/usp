#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fila.h"

#define BUFFERSIZE 1000

char *ler_string() {
	char buffer[BUFFERSIZE];
	if (fgets(buffer, BUFFERSIZE, stdin) == NULL) {
		return NULL;
	}
	buffer[strcspn(buffer, "\n")] = 0;
	char *retorno = malloc(sizeof(char)*(strlen(buffer)+1));
	if (retorno == NULL) {
		return NULL;
	}
	strcpy(retorno, buffer);
	return retorno;
}

elem preencher_elem(char *input) {
	char nome[TAM];
	int idade;
	int condicao;
	sscanf(input, "%*s %s %d %d", nome, &idade, &condicao);
	
	elem retorno;
	strcpy(retorno.nome, nome);
	retorno.idade = idade;
	retorno.cond = condicao;

	return retorno;
}

void print_elem(elem entrada) {
	printf("%s %d %d\n", entrada.nome, entrada.idade, entrada.cond);
	return;
}

int main(){
	int n;
	char *n_string = ler_string();
	sscanf(n_string, "%d", &n);
	fila_t *p1 = criar();
	fila_t *p2 = criar();
	fila_t *p3 = criar();
	fila_t *p4 = criar();
	
	for (int i = 0; i < n; i++){
		char *entrada = ler_string();
		if (entrada[0] == 'S') {
			elem x;
			if(isEmpty(p1) == 0){
				remover(p1, &x);
				print_elem(x);
			}
			else if(isEmpty(p2) == 0){
				remover(p2, &x);
				print_elem(x);
			}
			else if(isEmpty(p3) == 0){
				remover(p3, &x);
				print_elem(x);
			}
			else if(isEmpty(p4) == 0){
				remover(p4, &x);
				print_elem(x);
			}
			else {
				printf("FILA VAZIA\n");
			}
		}
		else if (entrada[0] == 'E') {
			elem x = preencher_elem(entrada);
			if(x.idade >= 60 && x.cond == 1) {
				inserir(p1, x);
			}
			else if(x.cond == 1) {
				inserir(p2, x);
			}
			else if(x.idade >= 60) {
				inserir(p3, x);
			}
			else {
				inserir(p4, x);	
			}
		}
		else {
			printf("OPERAÇÃO INVÁLIDA\n");
		}
		free(entrada);
	}
	destruir(p1);
	destruir(p2);
	destruir(p3);
	destruir(p4);
	return 0;
}
