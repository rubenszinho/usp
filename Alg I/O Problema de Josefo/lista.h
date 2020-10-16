#define TamFila 1000
#define TAM 50

typedef struct _elem {
	char nome[TAM];
	int idade;
	int cond;
} elem;
typedef struct fila fila_t;

fila_t *criar();
int isEmpty(fila_t *f);
int isFull(fila_t *f);
int inserir(fila_t *f, elem x);
int remover(fila_t *f, elem *x);
void destruir(fila_t *f);
