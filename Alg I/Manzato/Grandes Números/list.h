#ifndef list_h
#define list_h
#include <stdlib.h>

typedef struct _node node;
typedef struct _list list;

list *list_create();
void list_destroy(list **input, void (*free_data_func)(void *));
int list_push(list *input, void *data, size_t data_size);
int list_pushend(list *input, void *data, size_t data_size);
void *list_pop(list *input);
void *list_popend(list *input);
void list_print(list *input, void (*func)(void *));
void list_print_rev(list *input, void (*printfunc)(void *));
int list_isempty(list *input);
unsigned long long int list_size(list *input);

node *list_head(list *input);
node *list_tail(list *input);
node *node_next(node *input);
node *node_prev(node *input);
void *node_data(node *input);

#endif
