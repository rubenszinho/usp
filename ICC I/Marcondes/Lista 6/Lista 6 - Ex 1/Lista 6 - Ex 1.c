/*1. Escreva uma função que recebe uma palavra e um arquivo de texto.
Assumir que o arquivo de texto contém 100 palavras, separadas por 
espaço. A função deve retornar quantas vezes a palavra ocorreu no 
arquivo de texto.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 100

int contando_ocorrencias(FILE *arquivo, char *string){
    int count;
    char linha[128];
    arquivo = fopen("Lista 6 - Ex 1.txt", "r");
    if (arquivo == NULL){ 
        printf("Erro ao abrir o arquivo");
        exit(1);
    }
    while (fgets(linha, sizeof(linha), arquivo) != NULL){
        if (strstr(linha, string) != NULL) count ++;
    }
    fclose(arquivo);
    return count;
}

int main(){
    //lendo string
    char buffer[TAM];
    fgets(buffer, TAM, stdin);
    buffer[strcspn(buffer, "\n")] = 0;

    //copiando buffer para a string
    int str_len = strlen(buffer);
    char *str = malloc(str_len + 1);
    strcpy(str, buffer);

    FILE *arq;
    printf("%s ocorreu %i vezes\n", str, contando_ocorrencias(arq, str));
    free(str);
return 0;
}