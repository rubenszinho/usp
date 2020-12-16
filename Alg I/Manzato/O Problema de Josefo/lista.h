typedef int elem;
typedef struct lista LISTA;
typedef struct no NO;
LISTA* cria();
elem josefo(LISTA *l, int k);
int insere(LISTA *l, elem x);
int busca(LISTA *l, elem x);
void remover(LISTA *l, NO *ant);
