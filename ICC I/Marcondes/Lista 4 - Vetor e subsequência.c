/*Leia dois vetores de inteiros. O primeiro vetor 
tem tamanho 5. O segundo vetor tem tamanho 3. 
Verifique se os elementos do segundo vetor é 
uma subsequência do primeiro vetor, ou seja, 
se os elementos do segundo vetor ocorrem (em ordem) 
no primeiro vetor.
Exemplo:

    Vetor 1 = [2 3 6 7 5]
    Vetor 2 = [3 6 7] Vetor 2 é uma subsequência do Vetor 1.

Quando encontrar uma subsequência, então escrever "SIM". 
Caso contrário, escrever "NAO".*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int* vet_1 = (int *)calloc(5, sizeof(int));
    int* vet_2 = (int *)calloc(3, sizeof(int));
    int numeroDigitado;
    
    for(int i = 0; i < 5; i ++){
        scanf("%d", &numeroDigitado);
        vet_1[i] = numeroDigitado;
    }

    for(int i = 0; i < 3; i ++){
        scanf("%d", &numeroDigitado);
        vet_2[i] = numeroDigitado;
    }

    for(int i = 0; i < 5; i ++){
        if(vet_1[i] == vet_2[0]){
            if(vet_1[i + 1] == vet_2[1]){
                if(vet_1[i + 2] == vet_2[2]){
                    printf("SIM");
                    return 0;
                }
            }            
        }
    }
    printf("NAO");
    return 0;
}