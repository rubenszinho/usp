#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

struct no {
    int chave;
    no_t* esq;
    no_t* dir;
};


arvore_t* criar() {
	arvore_t* a = (arvore_t*)malloc(sizeof(arvore_t));
	a->raiz = NULL;
	return a;
}


void finalizar(no_t* raiz) {
	if(raiz != NULL){
		finalizar(raiz->esq);
		finalizar(raiz->dir);
		free(raiz);
	}
}

//OPERACOES DESTINADAS À FUNCAO IMPRESSÃO ABAIXO
int cheque_pai(no_t* raiz, no_t* pai){
	int pai_val;
		if(pai == NULL)
			pai_val = -1;
		else
			pai_val = pai->chave;
return pai_val;
}

int altura(no_t* raiz) {
	if(raiz == NULL || raiz->chave == -1)
		return 0;
	
	int alt_esq = 1 + altura(raiz->esq);
	int alt_dir = 1 + altura(raiz->dir);
	
	if(alt_esq > alt_dir)
		return alt_esq;	
	else
		return alt_dir;
}

int cheque_grau(no_t* raiz) {
	int grau;
		if((raiz->esq == NULL || raiz->esq->chave == -1) && (raiz->dir == NULL || raiz->dir->chave == -1))
			grau = 0;
		else if((raiz->esq != NULL && raiz->esq->chave != -1) && (raiz->dir != NULL && raiz->dir->chave != -1))
			grau = 2;
		else
			grau = 1;
return grau;
}

//pos == esq(0) ou dir(1)
int cheque_filhos(no_t* raiz, int pos) {
	int filho;
	if(pos == 0) {
		if(raiz->esq == NULL)
			filho = -1;
		else
			filho = raiz->esq->chave;
	}
	else {
		if(raiz->dir == NULL)
			filho = -1;
		else
			filho = raiz->dir->chave;
	}
return filho;
}

void cheque_tipo(no_t* pai, no_t* raiz) {
		if(pai == NULL)
			printf("raiz");
		else if((raiz->esq == NULL || raiz->esq->chave == -1) && (raiz->dir == NULL || raiz->dir->chave == -1))
			printf("folha");
		else
			printf("interno");	
}

void imprimir(arvore_t* a, no_t* raiz) {
	if(a == NULL)
		return;
	if(raiz != NULL && raiz->chave != -1) {
		printf("no %d: pai = ", raiz->chave);
		no_t* pai = busca_pai(a->raiz, raiz->chave);
		printf("%d, ", cheque_pai(raiz, pai));
		
		printf("altura = %d, ", altura(raiz));
		
		printf("grau = ");
		printf("%d, ", cheque_grau(raiz));
		
		printf("filhos = (");
		int pos = 0; //esq
		printf("%d,", cheque_filhos(raiz, pos));
		pos = 1; //dir
		printf("%d", cheque_filhos(raiz, pos));
		printf("), ");

		printf("tipo = ");
		cheque_tipo(pai, raiz);
		
		printf("\n");
		imprimir(a, raiz->esq);
		imprimir(a, raiz->dir);
	}
}

no_t* busca(no_t* raiz, int x)
{
	if(raiz == NULL)
		return NULL;
	if(raiz->chave == x)
		return raiz;

	no_t* p = busca(raiz->esq, x);
	if(p == NULL)
		p = busca(raiz->dir, x);

	return p;
}


no_t* busca_pai(no_t* raiz, int x){
	if(raiz == NULL)
		return NULL;
	
	if(raiz->esq != NULL && raiz->esq->chave == x)
		return raiz;
	if(raiz->dir != NULL && raiz->dir->chave == x)
		return raiz;
	
	no_t* p = busca_pai(raiz->esq, x);
	if(p == NULL)
		p = busca_pai(raiz->dir, x);

	return p;
}


//se pai == -1 => inserir na raíz
//caso contrário, insere do lado esquerdo de pai
int inserir_esq(arvore_t* a, int x, int pai){
	if(a == NULL)
		return -1;
	no_t* p = (no_t*)malloc(sizeof(no_t));
	p->esq = NULL;
	p->dir = NULL;
	p->chave = x;

	if(pai == -1){
		if(a->raiz == NULL){
			a->raiz = p;
		}
		else{
			free(p);
			return 0;
		}
	}
	else{
		no_t* aux = busca(a->raiz, pai);
		if(aux != NULL && aux->esq == NULL){
			aux->esq = p;
		}
		else{
			free(p);
			return 0;
		}
	}
	return 1;
}


int inserir_dir(arvore_t* a, int x, int pai) {	
	if(a == NULL)
		return -1;
	no_t* p = (no_t*)malloc(sizeof(no_t));
	p->esq = NULL;
	p->dir = NULL;
	p->chave = x;

	if(pai == -1){
		if(a->raiz == NULL) {
			a->raiz = p;
		}
		else{
			free(p);
			return 0;
		}
	}
	else {
		no_t* aux = busca(a->raiz, pai); 
		if(aux != NULL && aux->dir == NULL) { 
			aux->dir = p;
		}
		else{
			free(p);
			return 0;
		}
	}
	return 1;
}


void liberar(arvore_t* a) {
	if(a == NULL)
		return;
	finalizar(a->raiz);
	free(a);
}