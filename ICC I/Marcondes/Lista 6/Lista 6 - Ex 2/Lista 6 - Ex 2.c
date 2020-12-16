/*2. Escreva uma função que leia um arquivo de texto (informado no parâmetro) e copie para um segundo 
arquivo de texto (definido no parâmetro) os 500 primeiros caracteres do arquivo lido.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void copiando_char(FILE *arquivo_1, FILE *arquivo_2){
    arquivo_1 = fopen("Lista 6 - Ex 2_1.txt", "r");
    arquivo_2 = fopen("Lista 6 - Ex 2_2.txt", "w");
    if (arquivo_1 == NULL || arquivo_2 == NULL){ 
        printf("Erro ao abrir um dos arquivos");
        exit(1);
    }
    char arq[500];
    fgets(arq, sizeof(arq), arquivo_1); //pegando os char por linha
    arq[strcspn(arq, "\n")]= 0;
    fputs(arq, arquivo_2); //imprimindo todos os chars
    fclose(arquivo_1);
    fclose(arquivo_2);
}

int main(){
    FILE *arq_1;
    FILE *arq_2;
    copiando_char(arq_1, arq_2);
return 0;
}