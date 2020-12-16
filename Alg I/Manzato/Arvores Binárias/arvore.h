typedef struct no no_t;

typedef struct arvore{
    no_t *raiz;
}arvore_t;

arvore_t* criar();
int arvoreVazia(no_t* raiz);
void finalizar(no_t *raiz);
void imprimir(arvore_t *a, no_t *raiz);
no_t* busca(no_t *raiz, int x);
no_t* busca_pai(no_t *raiz, int x);
int inserir_esq(arvore_t *a, int x, int pai);
int inserir_dir(arvore_t *a, int x, int pai);
void liberar(arvore_t *a);




