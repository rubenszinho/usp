/*Escreva um programa para converter uma cadeia de caracteres de letras maiúsculas em letras minúsculas.
DICA: pesquisar sobre código ASCII.*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TAM 1000
int main(){
    char buffer[TAM];
    fgets(buffer, TAM, stdin);
    buffer[strcspn(buffer, "\n")] = 0;
    int tam = strlen(buffer);
    char *c = malloc(sizeof(char)*(tam+1));
    strcpy(c, buffer);
    for(int i = 0; i < tam; i ++){
        if(c[i] < 90)
            c[i] += 32;
        printf("%c", c[i]); 
    }
    free(c);
return 0;
}