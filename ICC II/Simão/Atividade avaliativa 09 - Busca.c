#include <stdio.h>
#include <stdlib.h>


// Programa para a resolução do exercício 09:

int shell(int v[], int n) {
    int s = 0;
    int gap = 1;

    while(gap <= n) {
        gap *= 2;
    }

    gap = gap / 2 - 1;

    while(gap > 0) {
        int i;
        int j;
		int k;
        for (k = 0; k < gap; k++){
            for (i = k + gap; i < n; i += gap){
                int x = v[i];
                (s)++;
                j = i - gap;

                while(j >= 0 && v[j] > x) {
                    (s)++;
                    (s)++;
                    v[j+gap] = v[j];
                    j-=gap;
                }
                if(j >= 0){              //Incrementa casos em que foram realizadas comparacoes, mas que nao entrou no while
                (s)++;
                }
                (s)++;
                v[j+gap] = x;
            }

        }
        gap /= 2;
    }

    return s;
}


int bin (int v[], int n, int x){
    int c=0;
    int f=n-1;
    while(c <= f){
            int m = (c+f)/2;
            if (v[m]==x){
                return 1;
            } else if (x <v[m]){
                f=m-1;
            } else {
                c=m+1;
            }
    }
    return 0;
}
int main (void){

int *elementos_N, *elementos_K; //vetores de tamanho variável
//int elementos_K[100];

int j, aux=0;
int N, K;

scanf("%d", &N);  //Ler o número de valores que conterá no vetor.
elementos_N = (int*)malloc(N*sizeof(int));
for (j=0;j<N;j++){ // Ler o vetor de entrada que contém N elementos.
    scanf("%d", &elementos_N[j]);
}

scanf("%d", &K);  //Ler o número de valores que conterá no segundo vetor, que será buscado.
elementos_K = (int*)malloc(sizeof(int)*K);
for (j=0;j<K;j++){ // Ler o vetor de entrada que contém K elementos.
    scanf("%d", &elementos_K[j]);
}

shell(elementos_N, N); // Aqui ordenaremos o vetor de entrada para poder utilizar a busca binária.


for (j=0;j<K;j++){
    aux=bin(elementos_N, N, elementos_K[j]);
    printf ("%d\n", aux);
}
return 0;

}

