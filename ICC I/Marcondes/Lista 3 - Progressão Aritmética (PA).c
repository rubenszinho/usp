//Faça um programa que calcule e escreva os seis primeiros termos de uma PA. 
//O programa deve ler o primeiro e sua razão.
//Escrever todos os termos em uma única linha, separados por espaço.

#include <stdio.h>
    int main(){
        int r, n, i;
        scanf("%d", &n);
        scanf("%d", &r);
        for(i = 1; i <= 6; i++){
            printf("%d ", n);
            n += r;
        }
    return 0;           
    }