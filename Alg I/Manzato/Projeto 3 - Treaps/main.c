#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"arvore.h"
#define TAM 20

//enviando endereco da string desejada por referencia para alterá-la sem a necessidade de retorno
void ler_string(char **string);;

int main() {
    
    arvore* a = criarArvore();
    int x, prioridade;

    //operacoes
    char *tipo_operacao;
    char *tipo_impressao;
    int n; //número de operacoes
    scanf("%d", &n);

    for(int i = 0; i < n; i ++){
        ler_string(&tipo_operacao);

        if (strcmp (tipo_operacao, "insercao") == 0){ //insercao
            scanf("%d", &x);
            scanf("%d", &prioridade);
            a->raiz = inserir(a->raiz, x, prioridade);
        }

        else if (strcmp (tipo_operacao, "remocao") == 0){ //remocao
            scanf("%d", &x);
            a->raiz = remover(a->raiz, x);
        }

        else if (strcmp (tipo_operacao, "buscar") == 0){ //busca
            scanf("%d", &x);
            busca(a->raiz, x);
        }

        else if (strcmp (tipo_operacao, "impressao") == 0) { //impressoes
            ler_string(&tipo_impressao);

            if (strcmp (tipo_impressao, "largura") == 0) { //impressao da largura
                largura(a->raiz);
                printf("\n");  
            }

            else if (strcmp (tipo_impressao, "preordem") == 0) { //impressao em ordem
                preOrdem(a->raiz);
                printf("\n");  
            }

            else if (strcmp (tipo_impressao, "posordem") == 0) { //impressao em pos ordem
                posOrdem(a->raiz);
                printf("\n");  
            }

            else if (strcmp (tipo_impressao, "ordem") == 0) { //impressao em pre ordem
                emOrdem(a->raiz);
                printf("\n");  
            }

            else{ //caso a string lida seja inválida
                printf("Tipo de impressao invalida\n");
                return 0;
            }            
        }

        else{ //caso a string lida seja inválida
            printf("Tipo de operacao invalida\n");
            return 0;
        }        
    }
    free(tipo_operacao);
    free(tipo_impressao);
    destruirArvore(a->raiz);
    return 0;
}

/*LENDO STRING DE FORMA DINÂMICA*/
void ler_string(char **string){
    char buffer[TAM];
    scanf("%s",buffer);
    buffer[strcspn(buffer, "\n")] = 0;
    int tam_buffer = strlen(buffer);
    *string = (char *)malloc(sizeof(char)*(tam_buffer));
    strcpy(*string ,buffer);
}