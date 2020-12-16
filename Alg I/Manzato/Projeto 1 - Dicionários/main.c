#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dict.h"
#include "operacoes.h"

int main() {
    //Inicializar dicionario
    dict *a = dict_create();
    //Ler a entrada do stdin
    entrada *in = le_entrada(stdin);
    //Enquanto não chegar no EOF e existir operação (não for apertado um enter sem nada)
    while (in != NULL && in->operacao) {
        //Rodar inserção, caso n de certo imprimir OPERACAO INVALIDA
        if (!strcmp(in->operacao, "insercao")) {
            if (!insercao(a, in)) {
                printf("OPERACAO INVALIDA\n");
            }
        //Rodar alteração, caso n de certo imprimir OPERACAO INVALIDA
        } else if (!strcmp(in->operacao, "alteracao")) {
            if (!alteracao(a, in)) {
                printf("OPERACAO INVALIDA\n");
            }
        //Rodar remoção, caso n de certo imprimir OPERACAO INVALIDA
        } else if (!strcmp(in->operacao, "remocao")) {
            if (!remocao(a, in)) {
                printf("OPERACAO INVALIDA\n");
            }                
        //Rodar busca, caso n de certo imprimir OPERACAO INVALIDA
        } else if (!strcmp(in->operacao, "busca")) {
            if (!busca(a, in)) {
                printf("OPERACAO INVALIDA\n");
            }
        //Rodar impressão, caso n de certo imprimir OPERACAO INVALIDA
        } else if (!strcmp(in->operacao, "impressao")) {
            if (!impressao(a, in)) {
                printf("OPERACAO INVALIDA\n");
            }
        //Caso não seja uma operação válida
        } else {
            printf("OPERACAO INVALIDA\n");
        }
        //Destruir a entrada que lemos
        destroi_entrada(&in);
        //Ler a próxima
        in = le_entrada(stdin);
    }
    //Destruir o dicionário
    destroi_dict(&a);
}
