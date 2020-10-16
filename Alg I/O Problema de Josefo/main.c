#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lista.h"

int main(){
	int T, n, k;
	scanf("%d", &T);
	while(T > 200){
		printf("Digite um valor dentro do intervalo [1,200]");
		scanf("%d", &T);
	}
	for (int i = 0; i <= T; i ++){
		scanf("%d %d", &n, &k);
		while(n > 1000 || n < 1 || k > 1000 || k < 1){
			printf("Digite sempre valores dentro do intervalo [1,1000]");
			scanf("%d %d", &n, &k);
		}

	}
	for (int i = 0; i <= T; i ++){
		printf("Caso %d: %d", i);

	}
return 0;
}
