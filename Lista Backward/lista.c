#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "lista.h"
typedef struct no NO;
struct no 
{
	elem info;
	NO *prox;
};

struct lista 
{
	NO *atual;
	int tam;
};

LISTA* cria()
{
	LISTA *l = (LISTA *)malloc(sizeof(LISTA));
	assert(l != NULL);
	l -> atual = NULL;
	l -> tam = 0;

	return l;
}

elem josefo(LISTA *l, int k)
{
	assert(l != NULL);
	assert(l->atual != NULL);
	NO *ant;
	while(l->tam > 1)
	{
		for(int i = 0; i < k; i++)
		{
			ant = l->atual;
			l->atual = l->atual->prox;
		}
	remover(l, ant);
	}
	return l->atual->prox->info;
}

int insere (LISTA *l, elem x)
{
	assert(l != NULL);
	if(busca(l, x) == 1) return 0;
	NO *p = (NO *)malloc(sizeof(NO));
	p->info = x;
	if(l->atual == NULL)
		p->prox = p;
	else
	{
		p->prox = l->atual->prox;
		l->atual->prox = p;
	}
	l->atual = p;
	l->tam ++;
	return 1;
}

int busca(LISTA *l, elem x)
{
	assert(l != NULL);
	NO *p;
	if(l->atual == NULL) return 0;
	p = l->atual;
	do{
		if(p->info == x) return 1;
		p = p->prox;
	} while(p != l->atual);
	return 0;
}

void remover(LISTA *l, NO *ant)
{
	assert(l != NULL);
	ant->prox = l->atual->prox;
	free(l->atual);
	l->atual = ant;
	l->tam--;
}