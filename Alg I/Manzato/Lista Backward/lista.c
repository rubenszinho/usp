#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "lista.h"

typedef struct no no_t;

struct no{
	elem info;
	no_t *prox;
	no_t *ant;
	no_t *back;
	int momento;
	int index;
};

struct lista{
	no_t *ini, *fim;
	int tam, tempo;
};

lista_t *cria(){
    lista_t *l;
    l = (lista_t*)malloc(sizeof(lista_t));
    assert(l != NULL);
    l->ini = NULL;
    l->fim = NULL;
    l->tam = 0;
	l->tempo = 0;
    return l;
}

void insira(lista_t *l, elem x, int j){
	assert(l != NULL);
	no_t *p = (no_t *)malloc(sizeof(no_t));
	p->info = x;
	p->prox = NULL;
	p->momento = l->tempo;
	//Inserindo na lista vazia
	if(l->ini == NULL){
		l->ini = p;
		l->fim = p;
		p->index = 0;
	}
	//Inserindo na lista com pelo menos um elemento
	else{
		l->fim->prox = p;
		p->ant = l->fim;
		p->index = p->ant->index + 1;	
	}
	l->fim = p;
	l->tempo++;
	l->tam++;
	no_t *aux = p->ant;
	for(int i = 0; i < j; i++){
		p->back = aux;
		if(p->back == NULL){
			break;
		}
		aux = aux->ant;
	}
	if(j == 0){
		p->back = NULL;
	}
}

int remova(lista_t *l, elem x){
	assert(l != NULL);
	if (l == NULL)
		return 0;
	no_t *p = l->ini;
	while(p != NULL){
		if(p->info == x){
			no_t *aux = p->prox;
			while(aux != NULL){
				if(aux->back == p){
					aux->back = NULL;
				}
				aux = aux->prox;
			}
			//Removendo com apenas um elemento na lista
			if(l->tam == 1){
				l->ini = NULL;
				l->fim = NULL;
				free(p);
			}
			//Removendo do inicio
			else if(p == l->ini){
				l->ini = l->ini->prox;
				l->ini->ant = NULL;
				free(p);
			}
			//Removendo do fim
			else if(p == l->fim){
				l->fim = l->fim->ant;
				l->fim->prox = NULL;
				free(p);
			}
			//Removendo do meio
			else{
				p->ant->prox = p->prox;
				p->prox->ant = p->ant;
				free(p);
			}

			arrume(l);
			l->tam--;
			l->tempo++;
			return 1;
		}
		else{
			p = p->prox;
		}
	}
	l->tempo++;
	return 0;
}

void arrume(lista_t *l){
	assert(l != NULL);
	//Arrumando as posições dos nós após a remoção de algum elemento
	no_t *p = l->ini;
	for(int i = 0; p != NULL; i++){
		p->index = i;
		p = p->prox;
	}
}

void imprima (lista_t *l){
	assert(l != NULL);
	no_t *p = l->ini;
	if(l->tam == 0){
		printf("-1\n");
		return;
	}
	while(p != NULL){
		if(p->back != NULL)
			printf("[%d,%d,%d] ", p->info, p->momento, p->back->index);
		else
			printf("[%d,%d] ", p->info, p->momento);
		p = p->prox;
	}
	printf("\n");
}

void libere(lista_t *l){
	assert(l != NULL);
	if(l != NULL){
		no_t *p = l->ini;
		while(p != NULL){
			l->ini = p->prox;
			free(p);
			p = l->ini;
		}
		free(l);
	}
}

int tamanho(lista_t *l){
	assert(l != NULL);
	return l->tam;
}

