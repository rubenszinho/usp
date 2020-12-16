#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int intercalar(int *vetor, int primeiro1, int ultimo1, int primeiro2, int ultimo2, int *c, int *t);

int merge_sort(int vetor, int n, int **matriz);

int merge(int *vetor, int primeiro, int ultimo, int *c, int *t);

int insercao(int vetor, int n, int **matriz);

int **alocar_matriz(int linhas, int colunas);

int **liberar_matriz(int linhas, int **matriz);


int main(){
	int q, i, j, maior=0;		// q é a quantidade de vetores, maior salva o tamanho do maior vetor para criar a matriz
	int **matriz;
	
	scanf("%d", &q);
	
	int tam_vetores[q];		// vetor que armazena o tamanho de cada um dos q vetores	
	
	for(i=0 ; i<q ; i++){
		scanf("%d", &tam_vetores[i]);
		
		if(tam_vetores[i]>maior){		// verifica qual o tamanho do maior vetor para criar a matriz
			maior = tam_vetores[i];
		}
	}
	
	matriz = alocar_matriz(q, maior);		// função que faz a alocação dinamica da matriz
	
	for(i=0 ; i<q ; i++){
		for(j=0 ; j<tam_vetores[i]; j++){
			scanf("%d", &matriz[i][j]);
		}
	}
	
	for(i=0 ; i<q ; i++){		// executa as funções que fazem o ordenamento de cada vetor
		insercao(i, tam_vetores[i], matriz);
		
		merge_sort(i, tam_vetores[i], matriz);
	}
	
	liberar_matriz(q, matriz);		// função que libera o espaço alocado para a matriz
	
	return 0;
}


int **alocar_matriz(int linhas, int colunas){		// função que faz a alocação dinamica da matriz
	int i;
	
	int **matriz;
	
	matriz = (int**) calloc(linhas, sizeof(int*));
	
	if(matriz == NULL){
		printf("\n\nErro: Memoria insuficiente!\n\n");
		return NULL;
	}
	
	for(i=0; i<linhas; i++){
		matriz[i] = (int*) calloc(colunas, sizeof(int));
		
		if(matriz[i] == NULL){
			printf("\n\nErro: Memoria insuficiente!\n\n");
			return NULL;
		}
	}
	
	return matriz;
}


int insercao(int vetor, int n, int **matriz){		// função que faz o ordenamento pelo metodo insertion
	int i, j, aux;
	int c = 0, t = 0;
	int vetor_copia[n];		// copia do vetor original que será ordenada.
	
	for(i=0 ; i<n ; i++){		// copia o vetor original da matriz para o vetor_copia para ser ordenado.
		vetor_copia[i] = matriz[vetor][i];
	}
	
	for (i = 1 ; i < n; i++){

        aux = vetor_copia[i];
        
        t++;

        for (j=i; j>0; j--){

            c++;
            
            if(aux >= vetor_copia[j - 1]){
            	break;	
            }

            vetor_copia[j] = vetor_copia[j - 1];
            
            t++;
        }
        
        vetor_copia[j] = aux;
        
        t++;
    }
	
	printf("I %d %d %d\n", n, t, c);
	
	return 0;
}

int **liberar_matriz(int linhas, int **matriz){			// função que libera o espaço alocado para a matriz	
	int i;
	
	if(matriz==NULL){
		return NULL;
	}
	
	for(i=0; i<linhas; i++){
		free(matriz[i]);
	}
	
	free(matriz);
	
	return NULL;
}

int merge_sort(int vetor, int n, int **matriz){			// função que cria uma copia do vetor para passar para a função merge
	int vetor_copia[n];		// copia do vetor original que será ordenada.
	int i;
	int c = 0;
	int t = 0;
	
	for(i=0 ; i<n ; i++){		// copia o vetor original da matriz para o vetor_copia para ser ordenado.
		vetor_copia[i] = matriz[vetor][i];
	}
	
	merge(vetor_copia, 0, n-1, &c, &t);			// executa a função merge passando como argumento o vetor copiado
	
	printf("M %d %d %d\n", n, t, c);
	
	return 0;
}

int merge(int *vetor, int primeiro, int ultimo, int *c, int *t){		// função que ordena pelo metodo merge recursivo	
	if(ultimo > primeiro){
		int meio = (primeiro + ultimo) / 2;
		
		merge(vetor, primeiro, meio, c, t);
		
		merge(vetor, meio+1, ultimo, c, t);
		
		intercalar(vetor, primeiro, meio, meio+1, ultimo, c , t);
	}
	
	return 0;
}

int intercalar(int *vetor, int primeiro1, int ultimo1, int primeiro2, int ultimo2, int *c, int *t){			// função auxiliar do merge
	int tam = (ultimo1 - primeiro1 + 1) + (ultimo2 - primeiro2 + 1);
	int auxiliar[tam];
	int i = primeiro1;
	int j = primeiro2;
	int k = 0;
	int l;
	
	while(i <= ultimo1 && j <= ultimo2){
		(*c)++;
		
		if(vetor[i] <= vetor[j]){
			auxiliar[k++] = vetor[i++];
			
			(*t)++;
		}
		else{
			auxiliar[k++] = vetor[j++];
			
			(*t)++;
		}
	}
	
	while(i <= ultimo1){
		auxiliar[k++] = vetor[i++];
		
		(*t)++;
	}
	
	while(j <= ultimo2){
		auxiliar[k++] = vetor[j++];
		
		(*t)++;
	}
	
	for(k = 0, l = primeiro1; l <= ultimo2; l++, k++){
		vetor[l] = auxiliar[k];
		
		(*t)++;
	}
	
	return 0;
}
