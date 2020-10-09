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
        char funcao[10];
        fgets(funcao, 10, stdin);
        funcao[strcspn(funcao, "\n")] = 0;
        if (strcmp(funcao,"SAI") == 0)
            printf("saiu");
        else if (strcmp(funcao,"ENTRA") == 0)
            printf("entrou");
        else{
            printf("invalido");
            return 0;
        }
    return 0;
    }