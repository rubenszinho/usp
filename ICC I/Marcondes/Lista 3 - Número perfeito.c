//Um número perfeito é um número inteiro para o qual a soma de todos os seus 
//divisores positivos próprios (excluindo ele mesmo) é igual ao próprio número.
//Faça um programa que leia um número inteiro, calcule (usando estruturas de 
//repetição) e escreva "SIM", caso seja um número perfeito. Caso contrário, 
//escreva "NAO".
//Exemplo de número perfeito: 6 = 1 + 2 + 3

#include <stdio.h> 
    int main(){
        int n, x = 0, i;
        scanf("%d", &n);
        for(i = 1; i < n; i ++){
            if(n % i == 0)
                x += i;
            if(x == n){
                printf("SIM");
                return 0;
                }               
        }
        printf("NAO");
        return 0;
    }