//Declare um vetor de floats com 5 posições. Preencha o vetor conforme valores
//definidos pelo usuário. Imprima o maior valor e a posição do maior valor 
//no vetor, um em cada linha.
#include <stdio.h>
#define TAM 5

int main(){
    float numeroDigitado, vet[tam], aux;
    int i, j;
    scanf("%d", &numeroDigitado);
    for (i = 0; numeroDigitado < TAM; i ++){
        vet[i] = numeroDigitado;
        if(vet[i] > vet[i + 1] && vet[i + 1] < tam )
            vet[i]
        scanf("%d", &numeroDigitado);
    }
    
        printf("%f\n%d", vet[tam], );
    }

    return 0;
}
