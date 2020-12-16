#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct filme{
    char nome[100];
    char genero[20];
    int ano;
};

struct filme *RecebaFilmes(struct filme filmes[5]);
void ImprimaFilmes(struct filme filmes[5]);
void ImprimaGenero(struct filme filmes[5], char _genero[20]);

void main(){
    struct filme filmes[5];
    struct filme *pfilme;
    int opcao;
    char p_genero[20];
    pfilme = RecebaFilmes (filmes);
    for (;;){
        printf("Digite 1 para visualizar os filmes produzidos entre 2001 e 2005 ou 2 para ver somente de um genero.\n");
        scanf("%d", &opcao);
        system("cls");
        if (opcao == 1){
            ImprimaFilmes(pfilme);
        }
        else{
            ImprimaGenero(pfilme, p_genero);
        }
        printf("Digite 1 para VOLTAR ou 2 para TERMINAR.\n");
        scanf("%d", &opcao);
        system("cls");
        if (opcao == 2)
            break;
    }

}

struct filme* RecebaFilmes (struct filme filmes[5]){
    char j[10];
    for(int i = 0; i < 5; i++){
        printf("Digite o nome do filme %d (sem caracteres especiais): ", i+1);
        gets(filmes[i].nome);
        printf("Digite o genero do filme %d (sem caracteres especiais): ", i+1);
        gets(filmes[i].genero);
        printf("Digite o ano de lancamento: ");
        scanf("%d", &filmes[i].ano);
        gets(j);
        system("cls");
    }
    return &filmes[0];
}

void ImprimaFilmes(struct filme filmes[5]){
    printf("Filmes produzidos entre 2001 e 2005:\n");
     for(int i = 0; i < 5; i++){
        if (filmes[i].ano >= 2001 && filmes[i].ano <= 2005){
        printf("Filme %d: %s\n", i+1, filmes[i].nome);
        printf("Genero: %s\n", filmes[i].genero);
        printf("Lancamento: %d\n\n", filmes[i].ano);
        }
    }
}

void ImprimaGenero(struct filme filmes[5],char _genero[20]){
    char j[10];
    gets(j); //para captar o enter anterior
    printf("Escolha um genero dado(ex: terror, suspense):\n");
    gets (_genero);
    system("cls");
    printf("Filmes do genero \"\%s\"\:\n", _genero);
    for (int i = 0; i < 5; i++){
        if (strcmp(filmes[i].genero, _genero) == 0){
            printf("filme %d: %s\n", i+1, filmes[i].nome);
            printf("genero: %s\n", filmes[i].genero);
            printf("Lancamento: %d\n\n", filmes[i].ano);
        }
    }
    if (strcmp(filmes[0].genero, _genero) != 0 && strcmp(filmes[1].genero, _genero) != 0 && strcmp(filmes[2].genero, _genero) != 0 && strcmp(filmes[3].genero, _genero) != 0 && strcmp(filmes[4].genero, _genero) != 0)
        printf ("GENERO \"\%s\"\ NAO INCLUSO\n\n ", _genero);
}
