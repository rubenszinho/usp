/*.3. Escreva uma função que receba dois arquivouivos de texto de até 100 string (separadas por espaço), 
contabilize e retorne quantas string em comum os arquivouivos possuem.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LINHA_TAM 128

//ordena_file muda a formatacao e cria outro aquivo para ajudar na contabilizacao das palavras em comum
void OrdenaFile(FILE *arquivo_ordenado, FILE *arquivo){
    char ch;
    while ((ch = fgetc(arquivo)) != EOF){ //lendo char a char
        if ((ch == ' ') || (ch == '\n')) fprintf(arquivo_ordenado,"\n");
        else fputc(ch, arquivo_ordenado);//imprimindo char a char
    }
    fseek(arquivo_ordenado, 0, SEEK_SET);//resetando o cursor
}

//como o proprio nome da funcao ja diz, conta strings comuns
int contabilizando_strings_comuns(FILE *arquivo_1, FILE *arquivo_2, FILE *arquivo_1_ordenado, FILE *arquivo_2_ordenado){
    arquivo_1 = fopen("Lista 6 - Ex 3_1.txt", "r");
    arquivo_2 = fopen("Lista 6 - Ex 3_2.txt", "r");
    arquivo_1_ordenado = fopen("Lista 6 - Ex 3_1_ordenado.txt", "w+");
    arquivo_2_ordenado = fopen("Lista 6 - Ex 3_2_ordenado.txt", "w+");
    if (arquivo_1 == NULL || arquivo_2 == NULL || arquivo_1_ordenado == NULL|| arquivo_2_ordenado == NULL){
        printf("Erro ao abrir um dos arquivos");
        exit(1);
    }

    //Ordenando txt 1 para fazer fgets
    char palavra_1[LINHA_TAM];
    OrdenaFile(arquivo_1_ordenado, arquivo_1);
    fclose(arquivo_1);

    //Ordenando txt 2 para fazer fgets
    char palavra_2[LINHA_TAM];
    OrdenaFile(arquivo_2_ordenado, arquivo_2);
    fclose(arquivo_2);
    
    //lendo linha por linha do arquivo ja reordenado com 1 palavra por linha para percorrer ambos e fazer a comparacao pelo fgets, que capta a quebra de linha
    int count = 0;
    while (fgets(palavra_1, sizeof(palavra_1), arquivo_1_ordenado) != NULL){
        while (fgets(palavra_2, sizeof(palavra_2), arquivo_2_ordenado) != NULL){
            if (strcmp(palavra_1, palavra_2) == 0 && strcmp(palavra_1, " ") != 0){
                count++;
            }
        }
        fseek(arquivo_2_ordenado, 0, SEEK_SET); //reseta o cursor
    }
    count++;
    fclose(arquivo_1_ordenado);
    fclose(arquivo_2_ordenado);
return count;
}

int main(){
    FILE *arq_1;
    FILE *arq_2;
    FILE *arq_1_ordenado;
    FILE *arq_2_ordenado;
    printf("%d\n", contabilizando_strings_comuns(arq_1, arq_2, arq_1_ordenado, arq_2_ordenado));
return 0;
}