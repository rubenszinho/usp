//Faça um programa que leia vários inteiros positivos e mostre, no final, a quantidade de números ímpares e a quantidade de números pares.
//O programa é encerrado quando entrar um número menor ou igual a zero.
//Imprimir cada quantidade em uma linha.

#include <stdio.h>
    int main(){
        int Np = 0, Ni = 0, N;
        scanf("%d", &N);
        while(N > 0){
            if(N % 2 == 0)
                Np++;
            else
                Ni++;
            scanf("%d", &N);
        }
        printf("%d\n%d", Ni, Np);
    return 0;
    }