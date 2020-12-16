#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 100

/*Ler um arquivo de texto, verificar sua existência e retornar 
o ponteiro do arquivo.*/
FILE *ler_arq_e_retornar_ponteiro(char nome[]){
    FILE *arq = fopen(nome, "r");
    if (arq == NULL){ 
        printf("Erro ao abrir o arquivo");
        exit(1);
    }
return arq;
}

/*Contar quantos caracteres o arquivo possui.*/
int conta_caracteres(FILE *arq, char *linha){
    int count = 0;
    while (fgets(linha, sizeof(linha), arq) != NULL){
        
    }
return count;    
}

/*Contar quantas palavras o arquivo possui.*/
int conta_palavra(FILE *arq, char *linha){
    int count = 0;
    
return count; 
}

/*Contar quantos linhas o arquivo possui.*/
int conta_linha(FILE *arq, char *linha){
    int count = 0;
    while (fgets(linha, sizeof(linha), arq) != NULL){
        count ++;
    }
return count; 
}

/*Apresentar a frequência de cada palavra no texto.*/
void conta_palavra_freq(FILE *arq, char *linha){
    int count = 0;
    char string[TAM];
    char str_texto;

    for(int i = 0; string[i] != '\0' ;i ++){
        fscanf(arq, "%c", &str_texto);
        if(string[i] == ' '){
            while (fgets(linha, sizeof(linha), arq) != NULL){
                if (strstr(linha, string) != NULL) count ++;
            }
            printf("%s ocorreu %i vezes\n", string, count);
        }
        string[i] = str_texto;
    }
return; 
}

/*Funcao main*/
int main(){
    char *nome = "Lista 7 - Parte 1.txt";
    FILE *arquivo = ler_arq_e_retornar_ponteiro(nome);
    arquivo = fopen(nome, "r");
    if (arquivo == NULL){ 
        printf("Erro ao abrir o arquivo");
        exit(1);
    }
    char linha[128];
    /*conta_caracteres(arquivo, linha);
    conta_palavra(arquivo, linha);
    conta_linha(arquivo, linha);*/
    conta_palavra_freq(arquivo, linha);
return 0;
}