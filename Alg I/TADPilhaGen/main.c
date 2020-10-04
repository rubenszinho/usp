#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main(void){
	int n, i, carta, cnt = 1, rodadas = 0;
	scanf("%d", &n);
	pilha_t *recebe = create();
	pilha_t *compra = create();
	pilha_t *descarte = create();
	pilha_t *morto = create();

	for (i = 0; i < n; i++){
		scanf("%d", &carta);
		push(recebe, carta);
	}

	while (isEmpty(recebe) == 0){
		pop(recebe, &carta);
		push(compra, carta);
	}

	while (isEmpty(compra) == 0 || isEmpty(descarte) == 0){
		while (isEmpty(compra) == 0){
			pop(compra, &carta);
			if (carta == cnt){
				push(morto, carta);
				cnt++;
			}
			else{
				push(descarte, carta);
			}
		}
		while (isEmpty(descarte) == 0){
			pop(descarte, &carta);
			push(compra, carta);
		}
		rodadas++;
	}
	printf("%d\n", rodadas);

	destroy(compra);
	destroy(descarte);
	destroy(morto);
	destroy(recebe);
	return 0;
}
