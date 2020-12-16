#include<stdio.h>
#include<stdlib.h>

int hash(int j, int m, int x){ //funcao que calcula o hash
    return ((x+j) % m); // x = valor | j = tentativa | m = tamanho da tabela
}

void inserir(int m, int *v){
    int x, y, j = 0;

    scanf("%d", &x);
    while (1){
        y = hash(j, m, x);

        if(v[y] == -2 || v[y] == x){ //se encontrar uma posicao vazia ou com valor repetido
            v[y] = x;
            break;
        }
        j++;
    }

    return;
}

void remover(int m, int *v){
    int x, y, j = 0;

    scanf("%d", &x);
    while (j < m){ //percorre no max a tabela inteira
        y = hash(j, m, x);

        if(v[y] == -2){
            break;
        }
        if(v[y] == x){
            v[y] = -1; //indica que houve um valor retirado naquela posicao
            break;
        }

        j++;
    }

    return;
}

void imprimir(int m, int *v){
    int x, y, j = 0;

    scanf("%d", &x);
    while (j < m){ //percorre no max a tabela inteira
        y = hash(j, m, x);

        if(v[y] == -2){
            printf("-1 ");
            return;
        }
        if(v[y] == x){
            printf("%d ", y);
            return;
        }

        j++;
    }

    //so chega aqui se percorreu a tabela inteira e nao foi achado
    printf("-1 ");
    return;
}

int main(){
    int i, n, d, b, m, *v;

    scanf("%d", &m); //capacidade da tabela
    v = (int *)calloc(m, sizeof(int)); //0 indica posicao inicialmente vazia
	for(int aux = 0; aux < m; aux++)
	{
		v[aux] = -2;
	}
    
    scanf("%d", &n); //numero de insercoes
    for(i=0; i<n; i++){
        inserir(m, v);
    }

    scanf("%d", &d); //numero de remocoes
    for(i=0; i<d; i++){
        remover(m, v);
    }

    scanf("%d", &b); //numero de buscas
    for(i=0; i<b; i++){
        imprimir(m, v);
    }

    free(v);
    v = NULL;

    return 0;
}
