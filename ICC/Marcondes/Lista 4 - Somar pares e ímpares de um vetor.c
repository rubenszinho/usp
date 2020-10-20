/*Ler um vetor de inteiros de tamanho n, com n definido pelo usuário. 
Imprimir a soma dos números pares e a soma dos números ímpares, um em cada linha.*/

#include <stdio.h>
#include <stdlib.h>
int main(){
    int n, numeroDigitado, som_i, som_p;
    scanf("%d", &n);
    int* vet = (int *)calloc(n ,sizeof(int));
    int* imp = (int *)calloc(n ,sizeof(int));
    int* par = (int *)calloc(n ,sizeof(int));

    for(int i = 0; i < n; i ++){
        scanf("%d", &numeroDigitado);
        vet[i] = numeroDigitado;
    }

    for(int i = 0; i < n; i ++){
        if(vet[i] % 2 == 1)
            imp[i] = vet[i];
        else
            par[i] = vet[i];
    }

    som_i = 0;
    som_p = 0;
    for(int i = 0; i < n; i ++){
        som_p += par[i];
        som_i += imp[i];
    }

    printf("%d\n%d",som_p, som_i);
    return 0;
}