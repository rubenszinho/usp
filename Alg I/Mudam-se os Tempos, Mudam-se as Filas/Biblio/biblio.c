#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "biblio.h"
#include "fila.h"

struct usuario {
	int id;
	char nome[100];
};

struct livro {
	int id;
	char titulo[100];
	int disp;
	fila_t *f;
	int user_id;
};

struct biblio {
	usuario_t usuarios[N_USERS];
	livro_t livros[N_LIVROS];
};

biblio_t *cria_biblio() {
	biblio_t *bib = (biblio_t *)malloc(sizeof(biblio_t));
	assert(bib != NULL);
	cadastra_usuarios(bib);
	cadastra_livros(bib);
	return bib;
}

void apaga_biblio(biblio_t *bib) {
	assert(bib != NULL);
	for(int i = 0; i < N_LIVROS; i++) {
		destruir(bib->livros[i].f);
	}
	free(bib);
}

void cadastra_usuarios(biblio_t *bib) {
	assert(bib != NULL);
	for(int i = 0; i < N_USERS; i++) {
		bib->usuarios[i].id = i;
		strcpy(bib->usuarios[i].nome, "Nome de usuario");
	}
}

void cadastra_livros(biblio_t *bib) {
	assert(bib != NULL);
	for(int i = 0; i < N_LIVROS; i++) {
		bib->livros[i].id = i;
		strcpy(bib->livros[i].titulo, "Titulo do livro");
		bib->livros[i].disp = 1;
		bib->livros[i].f = criar();
		bib->livros[i].user_id = -1;
	}
}

int consulta_usuario(biblio_t *bib, int user_id) {
	assert(bib != NULL);
	if(user_id < 0 || user_id >= N_USERS) {
		return 0;
	}
	return 1;
}

int consulta_livro(biblio_t *bib, int livro_id) {
	assert(bib != NULL);
	if(livro_id < 0 || livro_id >= N_LIVROS) {
		return 0;
	}
	return 1;
}

int livro_disponivel(biblio_t *bib, int livro_id) {
	assert(bib != NULL);
	return bib->livros[livro_id].disp;
}

void emprestar_livro(biblio_t *bib, int user_id, int livro_id) {
	assert(bib != NULL);
	bib->livros[livro_id].disp = 0;
	bib->livros[livro_id].user_id = user_id;
}

int inserir_fila(biblio_t *bib, int user_id, int livro_id) {
	assert(bib != NULL);
	if(inserir(bib->livros[livro_id].f, (void *)&bib->usuarios[user_id]) == 0)
		return 0;
	return 1;
}

void devolver_livro(biblio_t *bib, int user_id, int livro_id) {
	if(isEmpty(bib->livros[livro_id].f) == 1) {
		bib->livros[livro_id].disp = 1;
		bib->livros[livro_id].user_id = -1;
	} else {
		usuario_t *novo_user;
		remover(bib->livros[livro_id].f, (void **)&novo_user);
		emprestar_livro(bib, novo_user->id, livro_id);
		printf("Emprestando para novo usuario da fila: %d\n", novo_user->id);
	}
		
}


