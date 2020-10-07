// Faça um programa que leia vários números inteiros positivos e imprima o maior e menor número (um em cada linha). O programa é encerrado se for informado um número zero ou negativo.

#include <stdio.h>
#include <stdlib.h>
int insercao(int *vet);
int tam;

int main(){
    int numeroDigitado, tam, *vet = (int*) malloc (sizeof(vet));
    scanf("%d", &numeroDigitado);
    for (tam = 0; numeroDigitado > 0; tam ++){
        int *vet = (int*) realloc (vet, sizeof(vet));
        vet[tam] = numeroDigitado;
        scanf("%d", &numeroDigitado);
    }
    insercao(vet);
    printf("%d %d", vet[0], vet[tam]);
    return 0;
}

int insercao(int *vet){
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



