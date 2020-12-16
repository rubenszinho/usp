#ifndef operacoes_h
#define operacoes_h
#include <stdio.h>
#include "dict.h"

typedef struct _entrada {
    char *operacao;
    char *chave;
    char *elemento;
} entrada;

entrada *le_entrada(FILE *stream);
int insercao(dict *a, entrada *in);
int busca(dict *a, entrada *in);
int impressao(dict *a, entrada *in);
int alteracao(dict *a, entrada *in);
int remocao(dict *a, entrada *in);
void destroi_entrada(entrada **in);

#endif
