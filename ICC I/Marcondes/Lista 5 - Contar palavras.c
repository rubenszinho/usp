/*Faça uma um programa que preencha uma matriz, em que cada linha da matriz é uma sentença. O total de sentenças é 3 (incluindo espaços!). Em seguida, o seu programa de retornar 
quantas palavras diferentes existem considerando todas as sentenças.*/
#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#define TAM 1000
void ordena_matriz(char array[TAM], char array_mat[3][TAM]);

int main(){
    char str_mat[3][TAM];

    //Primeira linha
    fgets(str_mat[0], TAM, stdin);
    str_mat[0][strcspn(str_mat[0], "\r")] = 0;
    str_mat[0][strlen(str_mat[0])] = '\0';

    //Segunda linha
    fgets(str_mat[1], TAM, stdin);
    str_mat[1][strcspn(str_mat[1], "\r")] = 0;
    str_mat[1][strlen(str_mat[1])] = '\0';

    //Terceira linha
    fgets(str_mat[2], TAM, stdin);
    str_mat[2][strcspn(str_mat[2], "\r")] = 0;
    str_mat[2][strlen(str_mat[2])] = '\0';

    //TRANSFORMANDO A STRING DE 2D EM 1D PARA FACILITAR NA ANALISE
    char str_vet[TAM], str_vet_aux[TAM];
    ordena_matriz(str_vet, str_mat);

    //PEGANDO AS OCORRENCIAS UNICAS DE CADA PALAVRA
    int i, j, l, count = 0, k = 0;
    char aux[TAM];
    //Criando uma string aux, para pegar palavra por palavra do vetor str_vet, e adcionando \n no inicio e no fim para evitar a contagem errada de um char (como um artigo por exemplo).
    while(1){
        for(aux[0] = '\n', i = 1; str_vet[k] != '\0' && str_vet[k] != '\n'; i ++, k ++){
            aux[i] = str_vet[k];
        }
        aux[i++] = '\n';
        aux[i++] = '\0';

        if (str_vet[k] == '\0') break; //Quebrar loop para caso k ja tenha chegado ao fim da string str_vet (a quebra precisa ser feita aqui para nao ultrapassar o tamanho da string).
        
        //Criando outro vetor de string auxiliar, só que este serve para ir cortando cada palavra ja procurada definida em aux.
        for(j = k + 1, l = 0; str_vet[j] != '\0'; j ++, l ++){
            str_vet_aux[l] = str_vet[j];
        }
        str_vet_aux[l++] = '\0';
        //strstr para localizar a primeira ocorrencia da string aux em str_vet_aux, caso ocorra, nao somar ao contador pois eventualmente ela vai se repetir e somar inevitavelmente.
        if(strstr(str_vet_aux, aux) == 0) {
            count++;
        }
        k++;
    }
    printf("%d\n", count);
return 0;
}

void ordena_matriz(char array[TAM], char array_mat[3][TAM]){
    int i, j, k = 0;
    for(i = 0; i < 3; i++){
        for (j  = 0; array_mat[i][j] != '\0'; j ++, k ++){
            if (array_mat[i][j] == ' '){ 
                array[k] = '\n';
                continue; //Pular para o proximo j++, k++
            }
            array[k] = array_mat[i][j];
        }
        if(i < 2) array[k++] = '\n'; //Adicionar espacos no final de cada linha excetuando a ultima (terceira).
    }
    array[k] = '\0';
}