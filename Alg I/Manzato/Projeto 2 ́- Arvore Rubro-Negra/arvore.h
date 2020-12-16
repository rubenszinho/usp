typedef int elem;
typedef struct no no;
typedef struct arvore arvore;

struct no{
    no *esq, *dir;
    elem info;
    int cor;
};

struct arvore {
    no *raiz;
};

arvore *criarArvore();
no *inserir(no *raiz, elem x);
void preOrdem(no *raiz);
void emOrdem(no *raiz);
void posOrdem(no *raiz);
no *buscaPredecessor(no *raiz, elem x);
no *buscaSucessor(no * root, elem x);
no *min(no *raiz);
no *max(no *raiz);
void destruirArvore(no *raiz);
