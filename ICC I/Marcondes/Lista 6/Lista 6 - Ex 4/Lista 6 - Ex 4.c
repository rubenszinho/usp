/*4. Escreva uma função que recebe um arquivo de texto e grave um segundo arquivo de 
texto cifrado, usando o código de César (pesquisar sobre o assunto).*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void criptografando(FILE *arquivo_1, FILE *arquivo_2, int cifra){
    arquivo_1 = fopen("Lista 6 - Ex 4_1.txt", "r");
    arquivo_2 = fopen("Lista 6 - Ex 4_2.txt", "w");
    if (arquivo_1 == NULL || arquivo_2 == NULL){ 
        printf("Erro ao abrir um dos arquivos");
        exit(1);
    }
    char linha[128];
    char c;

    while (fgets(linha, sizeof(linha), arquivo_1) != NULL){ //Pegar por linha
        for(int i = 0; i < strlen(linha); i++){
            //Fazer a conversao a partir do codigo ASCII decimal de cada char, e também evitar que o calculo pegue codigos ASCIIS de chars fora do alfabeto, e evitar que converta espacos
            if ((65 <= (int)linha[i] && (int)linha[i] <= 90)) linha[i] = (((linha[i] - 65) + cifra) % 26) + 65;
            if ((97 <= (int) linha[i] && (int)linha[i] <= 122)) linha[i] = (((linha[i] - 97) + cifra) % 26) + 97; 
        }
        fputs(linha, arquivo_2); //Imprimir a criptografia no arquivo 2
    }
    fclose(arquivo_1);
    fclose(arquivo_2);    
}

int main(){
    FILE *arq_1;
    FILE *arq_2;  
    int chave;
    printf("insira a chave para a encriptacao:\n");
    scanf("%d", &chave);
    chave = chave % 26; //Para caso a chave seja maior que 26, garantir que pegue um ciclo que não ultrapasse o alfabeto (que tem 26 letras)
    criptografando(arq_1, arq_2, chave);
return 0;       
}