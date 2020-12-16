#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "dict.h"

//O número de camadas esperado é log2(n), sendo n a capacidade esperada da lista
#define MAX_LEVELS 13

//Variável global para evitar inicializar o rand duas vezes (e gerar o mesmo número, já que são gerados BEM MAIS que 1 número por segundo)
int seed = 0;

//no corresponde a um nó da skip list
struct no_t {
    //A chave
    char *chave;
    //O elemento
    char *elem;
    //Em qual altura ele está primariamente (é acessível de nós com altura igual ou menor a esta)
    int altura;
    //Um vetor de próximos, um pra cada nível
    struct no_t *proximo[MAX_LEVELS];
};

//Uma estrutura auxiliar, contendo a cabeça da lista
struct _dict {
    no *cabeca;
};


//Uma função que gera um número entre 1 e max
int random_level(int max) {
    int level = 1;
    if (!seed) {
        srand(time(NULL));
        seed = 1;
    }

    while (level < max && (rand() > RAND_MAX / 2) ) {
        level += 1;
    }
    return level;
}


//Strdup está definido no POSIX e não no C, então vamos fazer um próprio pra evitar problemas
char *my_strdup(const char *source) {
    int len = strlen(source)+1;
    char *dest = malloc(len*sizeof(char));
    strcpy(dest, source);
    return dest;
}


dict *dict_create() {
    //Alocar estrutura dict
    dict *new_dict = malloc(sizeof(dict));
    if (new_dict == NULL) return NULL;
    //Alocar no cabeca
    //Damos calloc para zerar a memória da cabeça
    no *cabeca = calloc(1, sizeof(no));
    if (cabeca == NULL) return NULL;

    //A altura da cabeça será a máxima
    cabeca->altura = MAX_LEVELS;

    new_dict->cabeca = cabeca;

    return new_dict;
}


char *no_elem(no *in) {
    return my_strdup(in->elem);
}


char *dict_get(dict *in, char *chave) {
    //Começar da cabeça
    no *atual = in->cabeca;
    //O nível em que estamos atualmente
    int level = in->cabeca->altura-1;
    //Enquanto o nó atual não for nulo, e o nível não for negativo
    while (atual != NULL && atual->proximo != NULL && level >= 0) {
        //Caso o próximo seja nulo, descer um nível
        if (atual->proximo[level] == NULL) {
            level -= 1;
        //Caso contrário
        } else {
            //Comparar a chave do próximo nó com a que buscamos
            int aux = strcmp(atual->proximo[level]->chave, chave);
            //Caso seja identica, retornar o elemento
            if (aux == 0) {
                return my_strdup(atual->proximo[level]->elem);
            //Caso seja menor alfabeticamente, avançar para o próximo nó
            } else if (aux < 0){
                atual = atual->proximo[level];
            //Caso seja maior alfabeticamente, descer um nível sem avançar
            } else {
                level -= 1;
            }
        }
    }
    
    //Se viemos aqui, ou o dict é inválido ou não encontramos a chave
    return NULL;
}
char *no_chave(no *in) {
    return my_strdup(in->chave);
}


//Destruir completamente
void free_no(no **in) {
    //Liberar a chave setar o ponteiro para NULL
    free((*in)->chave);
    (*in)->chave = NULL;
    //Liberar o elemento e setar o ponteiro para NULL
    free((*in)->elem);
    (*in)->elem = NULL;

    //Liberar a estrutura e setar o ponteiro para NULL
    free(*in);
    in = NULL;
}


int dict_set(dict *in, char *key_in, char *value_in) {
    //Vetor com os nós anteriores
    no *previous[MAX_LEVELS];
    //Vetor auxiliar, começando da cabeça
    no *atual = in->cabeca;
    //Nível atual (começando do máximo)
    int level = in->cabeca->altura - 1;

    //elemento do nó, para não mover a string para cá
    char *elem = my_strdup(value_in);

    //Enquanto não chegarmos no fim da lista e nem passarmos o fundo
    while (atual != NULL && atual->proximo != NULL && level >=0) {
        //Guardar o atual no nível
        previous[level] = atual;
        //Caso o próximo do nível seja nulo
        if (atual->proximo[level] == NULL) {
            //Descer um nível
            level -= 1;
        } else {
            //Comparar strings
            int aux = strcmp(atual->proximo[level]->chave, key_in);
            //Caso seja a que buscamos
            if (aux == 0) {
                //Liberar o elemento do nó
                free(atual->proximo[level]->elem);
                //Alterar para o novo
                atual->proximo[level]->elem = elem;
                //Fim
                return 1;
            } else if (aux > 0) {
                //Descer um nível, sem avançar
                level -= 1;
            } else {
                //Avançar
                atual = atual->proximo[level];
            }
        }
    }
    //Alocar novo nó
    no *no_novo = malloc(sizeof(no));
    if (no_novo == NULL) return 0;
    //Altura aleatória
    no_novo->altura = random_level(in->cabeca->altura);
    //Copiar chave passada e guardar
    no_novo->chave = my_strdup(key_in);
    //Guardar elemento (Já copiado previamente)
    no_novo->elem = elem;

    //Colocar null em todos os próximos de níveis superiores a altura do nó
    for (int i = MAX_LEVELS -1; i > no_novo->altura; i--) {
        no_novo->proximo[i] = NULL;
    }
    //Para inserir, vamos pegar o vetor de anteriores
    //O próximo dos anteriores passa a ser o novo vetor
    //E o próximo do novo vetor será o antigo próximo dos anteriores
    for (int i = no_novo->altura -1; i >= 0; i--) {
        no_novo->proximo[i] = previous[i]->proximo[i];
        previous[i]->proximo[i] = no_novo;
    }
    //Caso a lista ainda esteja vazia, temos que atualizar a cabeça
    if (in->cabeca == NULL) {
        in->cabeca = no_novo;
    }
    //Tudo em ordem
    return 1;
}


int dict_unset(dict *in, char *chave) {
    //Anteriores
    no *previous[MAX_LEVELS];
    //Ponteiro auxiliar, começãndo na cabeça
    no *atual = in->cabeca;
    //Nível máximo
    int level = in->cabeca->altura - 1;

    int cmp = 0;
    //Bucar na lista
    while (atual != NULL && level >= 0) {
        //Guardar o atual
        previous[level] = atual;
        //Caso não tenha nada na frente
        if (atual->proximo[level] == NULL) {
            //Descer um nível
            level -= 1;
        } else {
            //Comparar as chaves
            cmp = strcmp(atual->proximo[level]->chave, chave);
            //Caso ultrapasse, descemos um nível sem avançar
            //Caso seja igual, também descemos, já que temos que preencher o previous
            if (cmp >= 0) {
                level -= 1;
            } else {
            //Caso ainda não chegue, avançar
                atual = atual->proximo[level];
            }
        }
    }

    //Caso tenha sido encontrado E o nó auxiliar não seja null (ou seja, a lista não esteja vazia)
    if (!cmp && atual != NULL) {
        //O que será removido é o que vem depois de onde paramos
        no *removed = atual->proximo[0];
        //Iterar no vetor de proximos
        for (int i = removed->altura - 1; i >= 0; i--) {
            //Os próximos do anterior serão os próximos daquele que está sendo removido
            previous[i]->proximo[i] = removed->proximo[i];
        }
        //Liberar o que removemos
        free_no(&removed);
        //Tudo certo
        return 1;
    } else {
        //Se não encontramos ou se o dict estava vazio
        return 0;
    }
}


no *dict_no_primeiro_char(dict *in, char character) {
    //Começar o auxiliar na cabeça da lista
    no *atual = in->cabeca;
    //Nível máximo
    int level = in->cabeca->altura-1;

    //Enquanto não chegarmos no fim da lista
    while (atual != NULL && atual->proximo != NULL && level >= 0) {
        //Caso o próximo seja o final da lista, descer um nível
        if (atual->proximo[level] == NULL) {
            level -= 1;
        } else {
            int cmp;
            //Comparar o primeiro caractere da chave do próximo com o que buscamos
            cmp = atual->proximo[level]->chave[0] - character;

            /* Caso o nó comece com o caractere correto e esteja na ultima camada
            (Precisamos estar na ultima camada para ter certeza,
            pois é possível que o que encontramos não seja a primeira ocorrencia
            de chave com o primeiro caractere correto)*/
            if (cmp == 0 && level == 0) {
                return atual->proximo[level];
            //O próximo nó ainda não tem o caractere, vamos para frente
            } else if (cmp < 0) {
                atual = atual->proximo[level];
            //O próximo nó ultrapassa, vamos descer
            } else {
                level -= 1;
            }
        }
    }
    //Se não encontrar
    return NULL;
}


no *proximo_no(no *atual) {
    return atual->proximo[0];
}


void destroi_dict(dict **in) {
    //Começar da cabeça
    no *atual = (*in)->cabeca;
    //Ponteiro auxiliar
    no *proximo = NULL;

    //Enquanto não chegarmos em NULL
    while (atual != NULL) {
        //O próximo será o próximo de nível mais baixo do atual
        proximo = atual->proximo[0];
        //Liberar a memória do nó atual
        free_no(&atual);
        //Ir para o próximo
        atual = proximo;
    }
    //Liberar a memória do dict em si, e setar o ponteiro para NULL
    free(*in);
    in = NULL;
}