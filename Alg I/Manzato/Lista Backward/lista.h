typedef int elem;
typedef struct lista lista_t;

lista_t *cria();
void insira(lista_t *l, elem x, int j);
int remova(lista_t *l, elem x);
void arrume(lista_t *l);
void imprima(lista_t *l);
void libere(lista_t *l);
int tamanho(lista_t *l);