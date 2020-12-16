//Declarar um vetor de inteiros de tamanho 100. Preencher o vetor com valores positivos, com entrada do usuário. Quando o usuário digitar zero ou um valor negativo, interromper a leitura. 
//Imprimir o vetor em ordem inversa (um número por linha).
#include <stdio.h>
#define TAM 100

int main(){
    int vet[TAM];
    int numeroDigitado, i, j;
    scanf("%d", &numeroDigitado);
    for (i = 0; numeroDigitado < TAM; i ++){
        vet[i] = numeroDigitado;
        scanf("%d", &numeroDigitado);
        if(numeroDigitado <= 0)
            break;
    }
    for(j = i; j >= 0; j--){
        printf("%d\n", vet[j]);
    }
    return 0;
}
