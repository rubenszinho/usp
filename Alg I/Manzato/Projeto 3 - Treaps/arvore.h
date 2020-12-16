typedef int elem;
typedef struct no no;
typedef struct arvore arvore;

struct no{
    no *esq, *dir;
    elem info, priori;
};

struct arvore {
    no *raiz;
};

arvore *criarArvore();
no *inserir(no *raiz, elem x, elem priori);
no *remover(no *raiz, elem x);
void *busca(no *raiz, elem x);
void largura(no *raiz);
void preOrdem(no *raiz);
void emOrdem(no *raiz);
void posOrdem(no *raiz);
void destruirArvore(no *raiz);
