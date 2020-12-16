#include <stdlib.h>
#include <stdio.h>
#include "list.h"
#define DEBUG 0

struct _node {
    void *data;
    struct _node *next;
    struct _node *prev;
};

struct _list {
    node *head;
    node *tail;
    unsigned long long int len;
};

// Cria uma lista vazia e a retorna. O(1)
list *list_create() {
    list *out = malloc(sizeof(list));
    if (out == NULL) return NULL;
    out->head = NULL;
    out->tail = NULL;
    out->len = 0;
    return out;
}

// Desaloca uma lista. Toma como argumento a lista e uma função para desalocar os items dela (passe simplesmente free se for uma primitiva ou vetor de primitivas). O(n)
void list_destroy(list **input, void (*free_data_func)(void *)) {
    while ((*input)->head != NULL) {
        node *next = (*input)->head->next;
        (*free_data_func)((*input)->head->data);
        free((*input)->head);
        (*input)->head = NULL;
        (*input)->head = next;
    }
    free(*input);
    *input = NULL;
}

// Insere um dado na cabeça da lista, dado ele e seu tamanho. O(1)
int list_push(list *input, void *data, size_t data_size) {
    if (input == NULL) return -1;
    // Criar novo nó
    node *new = malloc(sizeof(node));
    if (new == NULL) return -1;

    // Alocar espaço do elemento
    new->data = malloc(data_size);
    if (new->data == NULL) {
        free(new);
        return -1;
    }

    // Seu próximo vai ser a antiga head
    new->next = input->head;
    // Seu anterior vai ser null
    new->prev = NULL;

    // A antiga head, caso exista, terá como anterior o novo nó
    if (input->head != NULL) input->head->prev = new;

    // A head da lista agora será o novo nó
    input->head = new;
    // Caso não tenha uma tail na lista, será o novo nó
    if (input->tail == NULL) input->tail = new;

    // Copiar dados
    for (int i = 0; i < data_size; i++) {
        *(char *)(new->data+i) = *(char *)(data+i);
    }
    input->len += 1;
    if (DEBUG) {
        printf("==--==\n");
        if (input->tail != NULL) printf("Tail: %d\n", *(int *)input->tail->data);
        else printf("Tail: NULL\n");
        if (input->tail != NULL) printf("Head: %d\n", *(int *)input->head->data);
        else printf("Head: NULL\n");
    }
    return 0;
}

// Insere um dado na cauda da lista, dado ele e seu tamanho. O(1)
int list_pushend(list *input, void *data, size_t data_size) {
    if (input == NULL) return -1;
    // Criar novo nó
    node *new = malloc(sizeof(node));
    if (new == NULL) return -1;

    // Alocar espaço do elemento
    new->data = malloc(data_size);
    if (new->data == NULL) {
        free(new);
        return -1;
    }

    // Seu próximo vai ser NULL
    new->next = NULL;
    // Seu anterior vai ser a antiga tail
    new->prev = input->tail;

    // A antiga tail, caso exista, terá como próximo o novo nó
    if (input->tail != NULL) input->tail->next = new;

    // A tail da lista agora será o novo nó
    input->tail = new;
    // Caso não tenha uma head na lista, será o novo nó
    if (input->head == NULL) input->head = new;


    // Copiar dados
    for (int i = 0; i < data_size; i++) {
        *(char *)(new->data+i) = *(char *)(data+i);
    }
    input->len += 1;
    if (DEBUG) {
        printf("==--==\n");
        if (input->tail != NULL) printf("Tail: %d\n", *(int *)input->tail->data);
        else printf("Tail: NULL\n");
        if (input->tail != NULL) printf("Head: %d\n", *(int *)input->head->data);
        else printf("Head: NULL\n");
    }
    return 0;
}

// Remove e retorna o elemento na cabeça da lista. O(1)
void *list_pop(list *input) {
    if (input == NULL || input->head == NULL) return NULL;
    // Armazenar próximo elemento
    node *next = input->head->next;
    // Pegar os dados
    void *data = input->head->data;
    free(input->head);
    // A nova head será a próxima do elemento removido
    input->head = next;
    // E essa head terá como anterior NULL, colocaremos caso exista
    if (input->head != NULL) input->head->prev = NULL;
    // Caso a head seja NULL, a lista está vazia, então colocar NULL na tail
    else input->tail = NULL;

    input->len -= 1;
    if (DEBUG) {
        printf("==--==\n");
        if (input->tail != NULL) printf("Tail: %d\n", *(int *)input->tail->data);
        else printf("Tail: NULL\n");
        if (input->tail != NULL) printf("Head: %d\n", *(int *)input->head->data);
        else printf("Head: NULL\n");
    }
    return data;
}

// Remove e retorna o elemento na cauda da lista. O(1)
void *list_popend(list *input) {
    if (input == NULL || input->tail == NULL) return NULL;
    // Armazenar elemento anterior
    node *prev = input->tail->prev;
    // Pegar os dados
    void *data = input->tail->data;
    free(input->tail);
    // A nova tail será a anterior do elemento removido
    input->tail = prev;
    // E essa tail terá como próximo NULL, colocaremos caso exista
    if (input->tail != NULL) input->tail->next = NULL;
    // Caso a tail seja NULL, a lista está vazia, então colocar NULL na head
    else input->head = NULL;

    input->len -= 1;
    if (DEBUG) {
        printf("==--==\n");
        if (input->tail != NULL) printf("Tail: %d\n", *(int *)input->tail->data);
        else printf("Tail: NULL\n");
        if (input->tail != NULL) printf("Head: %d\n", *(int *)input->head->data);
        else printf("Head: NULL\n");
    }
    return data;
}

// Imprime a lista, usando a função print dada. Na ordem head->tail. O(n)
void list_print(list *input, void (*printfunc)(void *)) {
    if (input == NULL) return;
    node *tmp = input->head;
    while (tmp != NULL) {
        (*printfunc)(tmp->data);
        tmp = tmp->next;
    }
}

// Imprime a lista, usando a função print dada. Na ordem tail->head. O(n)
void list_print_rev(list *input, void (*printfunc)(void *)) {
    if (input == NULL) return;
    node *tmp = input->tail;
    while (tmp != NULL) {
        (*printfunc)(tmp->data);
        tmp = tmp->prev;
    }
}

// Retorna 1 se o vetor estiver vazio, 0 caso contrário. O(1)
int list_isempty(list *input) {
    if (list_size(input) == 0) return 1;
    else return 0;
}

// Retorna o tamanho da lista. O(1)
unsigned long long int list_size(list *input) {
    if (input == NULL) return 0;
    return input->len;
}

// Retorna o nó cabeça
node *list_head(list *input) {
    if (input == NULL) return NULL;
    return input->head;
}
// Retorna o nó cauda
node *list_tail(list *input) {
    if (input == NULL) return NULL;
    return input->tail;
}
// Retorna o próximo nó
node *node_next(node *input) {
    if (input == NULL) return NULL;
    return input->next;
}
// Retorna o nó anterior
node *node_prev(node *input) {
    if (input == NULL) return NULL;
    return input->prev;
}
// Retorna os dados de um nó
void *node_data(node *input) {
    if (input == NULL) return NULL;
    return input->data;
}

