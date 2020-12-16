#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dict.h"
#include "operacoes.h"

#define BUFFER_TAM 4096

//Le uma entrada da stream dada (normalmente stdin), coloca na estrutura entrada e a retorna
entrada *le_entrada(FILE *stream) {
    char buffer[BUFFER_TAM];
    //Caso não seja possível ler ou atingirmos um EOF
    if (fgets(buffer, BUFFER_TAM, stream) == NULL) return NULL;

    char buffer_operacao[BUFFER_TAM];
    char buffer_chave[BUFFER_TAM];
    char buffer_elem[BUFFER_TAM];

    int lidos = sscanf(buffer, "%s %s %[^\n]", buffer_operacao, buffer_chave, buffer_elem);

    entrada *nova_entrada = malloc(sizeof(entrada));
    nova_entrada->operacao = NULL;
    nova_entrada->chave = NULL;
    nova_entrada->elemento = NULL;

    //Caso tenhamos operação
    if (lidos >= 1) {
        int len = strlen(buffer_operacao)+1;
        nova_entrada->operacao = malloc(sizeof(char)*len);
        strcpy(nova_entrada->operacao, buffer_operacao);
    }
    //Caso tenhamos chave
    if (lidos >= 2) {
        int len = strlen(buffer_chave)+1;
        nova_entrada->chave = malloc(sizeof(char)*len);
        strcpy(nova_entrada->chave, buffer_chave);
    }
    //Caso tenhamos elemento
    if (lidos >= 3) {
        int len = strlen(buffer_elem)+1;
        nova_entrada->elemento = malloc(sizeof(char)*len);
        strcpy(nova_entrada->elemento, buffer_elem);
    }

    return nova_entrada;
}


int insercao(dict *a, entrada *in) {
    if (in == NULL || in->chave == NULL || in->elemento == NULL) return 0;
    char *buscado = dict_get(a, in->chave);
    if (buscado == NULL) {
        //Apenas insere se ele não já existir
        return dict_set(a, in->chave, in->elemento);
    } else {
        free(buscado);
        return 0;
    }
}


int busca(dict *a, entrada *in) {
    if (in == NULL || in->chave == NULL) return 0;

    char *encontrado = dict_get(a, in->chave);
    //Se não encontrar
    if (encontrado == NULL) return 0;

    printf("%s %s\n", in->chave, encontrado);
    free(encontrado);
    return 1;
}


int impressao(dict *a, entrada *in) {
    if (in == NULL || in->chave == NULL) return 0;
    //Começar do primeiro alfabetico que começa com o caractere
    no *atual = dict_no_primeiro_char(a, in->chave[0]);
    if (atual == NULL) return 0;
    //Enquanto n chegarmos no fim da lista
    while (atual != NULL) {
        //Guardar a chave do no atual
        char *chave = no_chave(atual);
        //Caso a chave NÃO comece com a letra que buscamos, é hora de parar
        if (chave[0] != in->chave[0]) {
            free(chave);
            break;
        }
        //Guardar o elemento
        char *elemento = no_elem(atual);
        //Imprimir chave e elemento
        printf("%s %s\n", chave, elemento);
        //Liberar memória
        free(chave);
        free(elemento);
        //Ir para a próxima
        atual = proximo_no(atual);
    }
    return 1;
}


int alteracao(dict *a, entrada *in) {
    if (in == NULL || in->chave == NULL || in->elemento == NULL) return 0;

    char *buscado = dict_get(a, in->chave);
    if (buscado == NULL) {
        return 0;
    } else {
        free(buscado);
        //Apenas altera se ainda não existir
        return dict_set(a, in->chave, in->elemento);
    }
}


int remocao(dict *a, entrada *in) {
    if (in == NULL || in->chave == NULL) return 0;

    return dict_unset(a, in->chave);
}


void destroi_entrada(entrada **in) {
    if ((*in)->elemento != NULL) free((*in)->elemento);
    if ((*in)->chave != NULL) free((*in)->chave);
    if ((*in)->operacao != NULL) free((*in)->operacao);
    free(*in);
    in = NULL;
}

