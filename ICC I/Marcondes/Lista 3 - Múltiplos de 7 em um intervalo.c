//Escreva um programa que apresente a quantidade de números múltiplos de 7
// no intervalo [10, 99999]

#include <stdio.h>
    int main(){
        int i, quanti;
        for(i = 10; i <= 99999; i++){
            if(i % 7 == 0)
                quanti++;
        }
        printf("%d", quanti);
    return 0;
    }