#include <stdio.h>

int tam;

int insercao(int vet[]);
int main(){
    scanf ("%d", &tam);
    int numeroDigitado, vetor[tam];

    for (int i = 0; i < tam; i++){
        scanf("%d", &numeroDigitado);
        vetor[i] = numeroDigitado;
    }

    insercao(vetor);
        printf( "%d ", vetor[tam - 1]);
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
