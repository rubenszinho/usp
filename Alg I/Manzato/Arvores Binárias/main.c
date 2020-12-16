#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

int main() {	
	arvore_t *a = criar();
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		int id, esq, dir;
		scanf("%d %d %d", &id, &esq, &dir);
		if(a->raiz == NULL){
			inserir_esq(a, id, -1);
		}
		inserir_esq(a, esq, id);
		inserir_dir(a, dir, id);
	}
	imprimir(a, a->raiz);
	liberar(a);
return 0;
}
