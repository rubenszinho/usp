#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fila.h"
typedef struct{
    char nome;
    int idade;
    int agravante;
}pessoa;
    int main(){
        // int n, tam;
        char funcao;
        // scanf("%d", tam)
        fgets(funcao, sizeof(funcao), stdin);
        if(funcao == "SAI")
            printf("saiu");
        else
        {
            printf("nao saiu");
        }  
    return 0;      
    }   