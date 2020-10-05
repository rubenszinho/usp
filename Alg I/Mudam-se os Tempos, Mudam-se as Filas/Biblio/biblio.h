#define N_USERS 20
#define N_LIVROS 20

typedef struct usuario usuario_t;
typedef struct livro livro_t;
typedef struct biblio biblio_t;

biblio_t *cria_biblio();
void apaga_biblio(biblio_t *bib);
void cadastra_usuarios(biblio_t *bib);
void cadastra_livros(biblio_t *bib);
int consulta_usuario(biblio_t *bib, int user_id);
int consulta_livro(biblio_t *bib, int livro_id);
int livro_disponivel(biblio_t *bib, int livro_id);
void emprestar_livro(biblio_t *bib, int user_id, int livro_id);
int inserir_fila(biblio_t *bib, int user_id, int livro_id);
void devolver_livro(biblio_t *bib, int user_id, int livro_id);