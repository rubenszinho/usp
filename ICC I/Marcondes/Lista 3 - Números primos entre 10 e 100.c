//Escreva um programa para calcular e imprimir os números primos no intervalo 
//(10,100). Imprimir os números primos todos em um única linha, separados por 
//espaço.

#include <stdio.h>
    int main(){
        int p, d, r;
        for(p = 11; p < 100; p++){
            r = 0;
            for(d = 1; p >= d; d++){   
                if(p % d == 0)
                    r++;
            }
            if(r == 2)
                printf("%d ", p);
        }
    return 0;    
    }