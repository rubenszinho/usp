/*Faça um programa para preencher um vetor de n inteiros, em que n é fornecido pelo usuário. 
Em seguida, imprimir o vetor de maneira ordenada, do maior para o menor. Nesse programa, 
não é permitido usar um segundo vetor auxiliar.*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int  tam, numeroDigitado, aux;
    scanf("%d", &tam);
    int* vet = (int *)calloc(tam, sizeof(int));

    for (int i = 0; i < tam; i++){
        scanf("%d", &numeroDigitado);
        vet[i] = numeroDigitado;
    }

    for (int i = 0; i < tam; i++){
        aux = vet[i];
        int j = i - 1;
        while (j > 0 && aux < vet[j]){
            vet[j + 1] = vet[j];
            j--;
        }
        vet[j + 1] = aux;
    }

    for (int i = tam - 1; i >= 0; i--)
        printf("%d\n", vet[i]);

    return 0;
}
