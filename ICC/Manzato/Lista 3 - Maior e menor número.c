
#include <stdio.h>
#include <stdlib.h>
int tam;

int insercao(int vet[]);
int main(){
    int numeroDigitado, vetor[];

    for (tam = 0;; tam++){
        scanf("%d", &numeroDigitado);
        if(numeroDigitado == 0 || numeroDigitado < 0)
            break;
        vetor[i] = numeroDigitado;
    }

    insercao(vetor);

    for (int j = 0; j < tam; j++){
        printf( "%d ", vetor[j]);
    }

    return 0;
}

int insercao(int vet[]){
    int i, j, x;
    for (i = 0; i < tam; i++){
        x = vet[i];
        j = i - 1;
        vet[i] = x;
        while (x < vet[j]){
            vet[j + 1] = vet[j];
            j--;
        }
        vet[j + 1] = x;
    }
    return 0;
}
