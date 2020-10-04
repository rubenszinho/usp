#define TamPilha 100000

typedef int element;
typedef struct pilha pilha_t;

pilha_t *create();
void destroy(pilha_t *p);
int isFull(pilha_t *p);
int isEmpty(pilha_t *p);
int push(pilha_t *p, element x);
int pop(pilha_t *p, element *x);
int topo(pilha_t *p, element *x);
