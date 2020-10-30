#include <stdio.h>
#include <string.h>
#include "lista.h"

int main()
{
	int T, n, k;
	LISTA *l;
	scanf("%d", &T);
	while(T > 200 || T < 1)
	{
		printf("Digite um valor dentro do intervalo [1,200]");
		scanf("%d", &T);
	}
	int casos[T];
	for (int i = 0; i < T; i ++)
	{
		l = cria();
		scanf("%d %d", &n, &k);
		while(n > 10000 || n < 1 || k > 10000 || k < 1)
		{
			printf("Digite sempre valores dentro do intervalo [1,1000]");
			scanf("%d %d", &n, &k);
		}
		for(int j = 1; j <= n; j++)
		{
			insere(l, j);
		}
		casos[i] = josefo(l, k);

	}
	for(int i = 0; i < T; i++)
		printf("Caso %d: %d \n", i + 1, casos[i] );
return 0;
}

