/*Escreva uma função que receba uma string e retorne a 
string sem vogais.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 1000
int main(){
    char buffer[TAM];
    fgets(buffer, TAM, stdin);
    buffer[strcspn(buffer, "\n")] = 0;
    int tam = strlen(buffer);
    char *str = malloc(sizeof(char)*(tam));
    char *str_aux = malloc(sizeof(char)*(tam));
    int i, j;
    strcpy(str, buffer);
    for (i = j = 0; i < tam; i ++){
        if(str[i] != 'a' && str[i] != 'e' && str[i] != 'i' && str[i] != 'o' && str[i] != 'u' && str[i] != 'A' && str[i] != 'E' && str[i] != 'I' && str[i] != 'O' && str[i] != 'U'){
            str_aux[j] = str[i];
            j++;
        }
    }
    printf("%s", str_aux);
return 0;
}