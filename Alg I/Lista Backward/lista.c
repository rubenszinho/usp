#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "lista.h"

typedef struct no no_t;

struct no {
	elem info;
	no_t *prox;
};

struct lista {
	no_t *ini, *fim;
	int tam;
};

lista_t *cria(){
    lista_t *l;
    l = (lista_t*)malloc(sizeof(lista_t));
    assert(l != NULL);
    l->ini = NULL;
    l->fim = NULL;
    l->tam = 0;
    return l;
}

void liberar(lista_t *l){
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

void insere(lista_t *l, elem x){
	assert(l != NULL);

	if(esta_na_lista(l, x) == 1)
		return;
	
	no_t *p = (no_t *)malloc(sizeof(no_t));
	p->info = x;
	p->prox = NULL;
	//LISTA VAZIA
	if(l->ini == NULL){
		l->ini = p;
	}

	//LISTA COM PELO MENOS UM ELEMENTO
	else{
		l->fim->prox = p;
	}
	l->fim = p;
	l->tam++;
}

int tamanho(lista_t *l){
	assert(l != NULL);
	return l->tam;
}

void imprimir (lista_t *l){
	assert(l != NULL);
	no_t *p = l->ini;
	while(p != NULL){
		printf("%d", p->info);
		p = p->prox;
	}
	printf("\n");
}

int esta_na_lista(lista_t *l, elem x){
	assert(l != NULL);
	no_t *p = l->ini;
	while(p != NULL){
		if(p->info == x)
			return 1;
		p = p->prox;
	}
	return 0;
}

int remover(lista_t *l, elem x){
	assert(l != NULL);
  
	no_t *ant = NULL;
	no_t *p = l->ini;
	
	while(p != NULL){
		if(p->info == x){
			//remover do inicio
			if(p == l->ini){
				l->ini = l->ini->prox;
				free(p);
			}

			//remover do fim
			else if(p == l->fim){
				l->fim = ant;
				l->fim->prox = NULL;
				free(p);
			}

			//remover do meio
			else{
				ant->prox = p->prox;
				free(p);
			}
			l->tam--;
			return 1;
		}
		else{
			ant = p;
			p = p->prox;
		}
	}
	return 0;
}