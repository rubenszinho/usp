//Declare um vetor de floats com 5 posições. Preencha o vetor conforme valores
//definidos pelo usuário. Imprima o maior valor e a posição do maior valor 
//no vetor, um em cada linha.
#include <stdio.h>
#include <stdlib.h>

#define TAM 5

int main(){
    float* vet = (float*) calloc(TAM, sizeof(float));
    float numeroDigitado;
    int pos = 0;
    for (int i = 0; i < TAM; i ++){
        scanf("%f", &numeroDigitado);
        vet[i] = numeroDigitado;
    }
    float aux = vet[0];
    for (int i = 0; i < TAM; i ++){
        if (aux < vet[i+1]){
            if(i + 1 == 5)
                break;
            aux = vet[i+1];
            pos = i+1;
        }
    }
    printf("%.1f\n%d", aux, pos);
    return 0;
}



