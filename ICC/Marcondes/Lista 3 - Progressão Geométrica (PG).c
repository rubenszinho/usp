//Faça um programa que leia o primeiro termo e a razão de um PG e retorno os 8 primeiros termos.
//Exibir os termos em um única linha, separados por espaço.

#include <stdio.h>
    int main(){
        int r, n, i;
        scanf("%d", &n);
        scanf("%d", &r);
        for(i = 1; i <= 8; i++){
            printf("%d ", n);
            n *= r;
        }
    return 0;           
    }