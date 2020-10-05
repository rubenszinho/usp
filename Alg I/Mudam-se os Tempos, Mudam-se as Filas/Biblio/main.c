#include <stdio.h>
#include "biblio.h"

int main() {
	int opt, user_id, livro_id;
	biblio_t *bib = cria_biblio();
	
	do {
		printf("Digite a opcao desejada:\n");
		printf("1 - Emprestar um livro\n");
		printf("2 - Devolver um livro\n");
		printf("0 - Sair do programa\n");
		scanf("%d", &opt);
		
		switch(opt) {
			case 1:
			printf("Digite o id do usuario: ");
			scanf("%d", &user_id);
			if(consulta_usuario(bib, user_id) == 0) {
				printf("Usuario nao cadastrado!\n");
				continue;
			}
			printf("Digite o id do livro: ");
			scanf("%d", &livro_id);
			if(consulta_livro(bib, livro_id) == 0) {
				printf("Livro nao cadastrado!\n");
				continue;
			}
			if(livro_disponivel(bib, livro_id) == 1) {
				emprestar_livro(bib, user_id, livro_id);
				printf("Emprestimo realizado com sucesso!\n");
			} else {
				inserir_fila(bib, user_id, livro_id);
				printf("Livro ja emprestado, inserindo na fila...\n");
			}
			break;
			
			case 2:			
			printf("Digite o id do livro: ");
			scanf("%d", &livro_id);
			if(consulta_livro(bib, livro_id) == 0) {
				printf("Livro nao cadastrado!\n");
				continue;
			}
			if(livro_disponivel(bib, livro_id) == 1) {
				printf("Livro ja foi devolvido!\n");
			} else {
				printf("Livro devolvido com sucesso!\n");
				devolver_livro(bib, user_id, livro_id);				
			}
		}
	} while(opt != 0);

	apaga_biblio(bib);
	return 0;
}
