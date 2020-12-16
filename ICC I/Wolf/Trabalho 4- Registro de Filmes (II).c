#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NUM_FILMES 5

int count_catalogo = 1;

struct filme {
    char nome[100];
    char genero[20];
    int ano;
    int num_catalogo;
    int apagado;
};

struct filme *receba_filmes(struct filme filmes[NUM_FILMES]);
void imprima_filmes(struct filme filmes[NUM_FILMES]);
void imprima_genero(struct filme filmes[NUM_FILMES], char _genero[20]);
void edite_filme(struct filme filmes[NUM_FILMES], int num_catalogo);
void receba_input(struct filme *f);
void remova_filme(struct filme *f);

int main()
{
    struct filme filmes[NUM_FILMES];
    struct filme *pfilme;

    int opcao = 0;
    int edite = 0;
    int filme_atual;
    char p_genero[20];
    pfilme = receba_filmes(filmes);
    while (opcao != 3) {
        printf("Digite 1 para visualizar os filmes produzidos entre 2001 e 2005 ou 2 para ver somente de um genero.\n");
        scanf("%d", &opcao);
        system("cls");
        if (opcao == 1){
            imprima_filmes(pfilme);
        }
        else {
            imprima_genero(pfilme, p_genero);
        }
        printf("Digite 1 para VOLTAR, 2 para editar ou apagar e 3 para TERMINAR.\n");
        scanf("%d", &opcao);
        if (opcao == 2) {
            printf("Digite o numero de catalogo: ");
            scanf("%d", &filme_atual);

            if (filme_atual < count_catalogo) {
                if (!filmes[filme_atual - 1].apagado) {
                    printf("Filme encontrado. Digite 1 para editar ou 2 para apagar: ");
                    scanf("%d", &edite);
                    getchar();

                    if (edite == 1) {
                        edite_filme(filmes, filme_atual);
                    } else if (edite == 2) {
                        remova_filme(&filmes[filme_atual - 1]);
                    } else {
                        printf("opção invalida");
                    }
                } else {
                    printf("filme não encontrado.");
                }
            }
        }
        system("cls");
    }

    return 0;
}

void remova_filme(struct filme *f)
{
    f->apagado = 1;
}

// DONT REPEAT YOURSELF!
void receba_input(struct filme *f)
{
    printf("Digite o nome do filme %d (sem caracteres especiais): ", f->num_catalogo);
    fgets(f->nome, 100, stdin);
    printf("Digite o genero do filme %d (sem caracteres especiais): ", f->num_catalogo);
    fgets(f->genero, 20, stdin);
    printf("Digite o ano de lancamento: ");
    scanf("%d", &(f->ano));
    getchar();
}

void edite_filme(struct filme filmes[NUM_FILMES], int num_catalogo)
{
    for (int i = 0; i < NUM_FILMES; i++) {
        if (filmes[i].num_catalogo == num_catalogo) {
            receba_input(&filmes[i]);
        }
    }
}

struct filme* receba_filmes(struct filme filmes[NUM_FILMES])
{
    for(int i = 0; i < NUM_FILMES; i++) {
        filmes[i].apagado = 0;
        filmes[i].num_catalogo = count_catalogo++;
        receba_input(&filmes[i]);
        system("cls");
    }
    return &filmes[0];
}

void imprima_filmes(struct filme filmes[NUM_FILMES])
{
    printf("Filmes produzidos entre 2001 e 2005:\n");
     for(int i = 0; i < NUM_FILMES; i++){
        if (filmes[i].ano >= 2001 && filmes[i].ano <= 2005 && !filmes[i].apagado) {
            printf("Filme %d: %s\n", i+1, filmes[i].nome);
            printf("Genero: %s\n", filmes[i].genero);
            printf("Lancamento: %d\n\n", filmes[i].ano);
        }
    }
}

void imprima_genero(struct filme filmes[2], char _genero[20])
{
    getchar();
    printf("Escolha um genero dado(ex: terror, suspense):\n");
    fgets(_genero, 20, stdin);
    system("cls");
    printf("Filmes do genero: %s", _genero);
    for (int i = 0; i < NUM_FILMES; i++) {
        if (strcmp(filmes[i].genero, _genero) == 0 && !filmes[i].apagado) {
            printf("filme %d: %s\n", i+1, filmes[i].nome);
            printf("genero: %s\n", filmes[i].genero);
            printf("Lancamento: %d\n\n", filmes[i].ano);
        }
    }
    if (strcmp(filmes[0].genero, _genero) != 0 && strcmp(filmes[1].genero, _genero) != 0 && strcmp(filmes[2].genero, _genero) != 0 && strcmp(filmes[3].genero, _genero) != 0 && strcmp(filmes[4].genero, _genero) != 0)
        printf ("GENERO \"%s\" NAO INCLUSO\n\n ", _genero);
}
