/*Escreva uma função que receba duas string s1 e s2.
Retorne SIM se s2 é uma substring de s1. Caso contrário,
retorne NAO.*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TAM 1000

int main(){
    char buffer[TAM];

    //str 1
    fgets(buffer, TAM, stdin);
    buffer[strcspn(buffer, "\n")] = 0;
    int str1_len = strlen(buffer);
    char *str1 = malloc(sizeof(char)*(str1_len + 1));
    strcpy(str1, buffer);

    //str 2
    fgets(buffer, TAM, stdin);
    buffer[strcspn(buffer, "\n")] = 0;
    int str2_len = strlen(buffer);
    char *str2 = malloc(sizeof(char)*(str2_len + 1));
    strcpy(str2, buffer);

    if(strstr(str1, str2) != NULL) 
        printf("SIM");
    else
        printf("NAO");
    free(str1);
    free(str2);
return 0;
}
