/*Escreva uma função que receba uma string e retorne SIM se é uma palíndroma. 
Caso contrário, retorne NAO.*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TAM 1000
int main(){
    char buffer[TAM];
    fgets(buffer, TAM, stdin);
    buffer[strcspn(buffer, "\n")] = 0;
    int tam = strlen(buffer);
    char *str = malloc(sizeof(char)*(tam+1));
    char *str_inv = malloc(sizeof(char)*(tam+1));
    strcpy(str, buffer);
    strcpy(str_inv, buffer);
    for (int i = 0; i < tam; i++) {
        str_inv[i] = str[tam-1-i];
    }
    if(strcmp (str, str_inv) != 0){
        printf("NAO\n");
    }
    else{
        printf("SIM\n");
    }
    free(str);
    free(str_inv);
    return 0;
}

