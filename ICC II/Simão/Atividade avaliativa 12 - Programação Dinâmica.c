#include <stdio.h>
#include <stdlib.h>

//cada esquina tem o numero de amigos caso a pessoa siga para baixo ou para a direita
typedef struct esquina
{
	int dir;
	int baixo;
}esquina;

typedef struct city
{
	//quarter é a matriz de esquinas
	esquina **quarter;
}city;

//aloca memória para o bairro por onde a pessoa vai passar
city* criar(int linhas, int colunas)
{
	city* c = (city*)malloc(sizeof(city));
	c->quarter = (esquina**)malloc(sizeof(esquina*)*linhas);
	for(int i = 0; i < linhas; i++)
	{
		c->quarter[i] = (esquina*)malloc(sizeof(esquina)*colunas);
	}
	return c;
}

// desaloca memoria do bairro
void destruir(city *c, int max_linha)
{
	for(int i = 0; i < max_linha; i++)
	{
		free(c->quarter[i]);
	}
	free(c->quarter);
	free(c);
}

//função recursiva
int anda(int **cache, city *c, int max_lin, int max_col, int lin_atual, int col_atual)
{
	int res;
	if(cache[lin_atual][col_atual] == -1)
	{
		if(lin_atual == max_lin && col_atual == max_col) //chegou na ultima posicao
			return 0;

		if(lin_atual == max_lin) //chegou na ultima linha. Só pode ir para a direita (é necessario ter essa chamada para "corrigir a rota" caso a ultima chamada tivesse sido para a posição debaixo)
			res = c->quarter[lin_atual][col_atual].dir + anda(cache, c, max_lin, max_col, lin_atual, col_atual+1);
		else if(col_atual == max_col) //chegou na ultima coluna. Só pode ir pra baixo(é necessario ter essa chamada para "corrigir a rota" caso a ultima chamada tivesse sido para a posição do lado)
			res = c->quarter[lin_atual][col_atual].baixo + anda(cache, c, max_lin, max_col, lin_atual+1, col_atual);
		else
		{
			//anda para a direita e chama a função andar começando da esquina à direita
			int anda_dir = c->quarter[lin_atual][col_atual].dir + anda(cache, c, max_lin, max_col, lin_atual, col_atual + 1); 

			//anda para baixo e chama a função andar começando da esquina de baixo
			int anda_baixo = c->quarter[lin_atual][col_atual].baixo + anda(cache, c, max_lin, max_col, lin_atual + 1, col_atual);
		
			if(anda_dir > anda_baixo)
				res = anda_dir;
			else
				res = anda_baixo;
		}
		cache[lin_atual][col_atual] = res;
	}
	else
	res = cache[lin_atual][col_atual];
	return res;
	
}

//função com programação dinamica que chama a recursao
int anda_pd(city *c, int max_lin, int max_col, int lin_atual, int col_atual)
{
	int **cache = (int**)malloc(sizeof(int*)*max_lin);
	for(int i = 0; i < max_lin; i++)
	{
		cache[i] = (int*)malloc(sizeof(int)*max_col);
		for(int j = 0; j < max_col; j++)
			cache[i][j] = -1;
	}

	int res = anda(cache, c, max_lin-1, max_col-1, lin_atual, col_atual);

	for(int i = 0; i < max_lin; i++)
	{
		free(cache[i]);
	}
	free(cache);
	return res;
}
int main()
{
	int linhas, colunas;	
	scanf("%d %d", &linhas, &colunas);
	city *c = criar(linhas, colunas);
		
	int esquina1, esquina2, dir, baixo;
	//preenche as ruas com a quantidade de amigos. As variáveis esquina1 e esquina2 não executam nada, apenas servem para ajudar a ler os valores necessarios(no caso, o terceiro inteiro a ser lido, que é o numero de amigos na rua à direita ou na rua abaixo)
	for(int i = 0; i < linhas; i++)
	{
		for(int j = 0; j < colunas; j++)
		{
			if(j == colunas - 1)
				c->quarter[i][j].dir = 0; //não tem mais rua pro lado
			else
			{
				scanf("%d%d%d", &esquina1, &esquina2, &dir);
				c->quarter[i][j].dir = dir;
			}
			if(i == linhas - 1)
				c->quarter[i][j].baixo = 0; //nao tem mais rua pra baixo
			else
			{
				scanf("%d%d%d", &esquina1, &esquina2, &baixo);
				c->quarter[i][j].baixo = baixo;
			}
		}
	}
	
	int res = anda_pd(c, linhas, colunas, 0, 0);
	printf("%d\n", res);
	destruir(c, linhas);	
}
