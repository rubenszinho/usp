#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"arvore.h"
int main(){
    arvore* a = criarArvore();
    int n; //numero de operacoes
    scanf("%d", &n);
    int o; //tipo de operacao
    int x; //numero inteiro a ser enviado para tipo de cada operacao nas chamadas das funcoes

    no *minimo, *maximo, *predecessor, *sucessor;
    for(int i = 0; i < n; i ++){
        scanf("%d", &o);
        switch (o){
            case 1: //insercao (enviando o valor inteiro para a funcao)
                scanf("%d", &x);
                a->raiz = inserir(a->raiz, x);
            break;

            case 2: //sucessor (imprimindo pelo endereco do nó)
                scanf("%d", &x);
                sucessor = buscaSucessor(a->raiz, x);
                if (sucessor == NULL) printf("erro");
                else printf("%d", sucessor->info);
                printf("\n");  
            break;

            case 3: //predecessor (imprimindo pelo endereco do nó)
                scanf("%d", &x);
                predecessor = buscaPredecessor(a->raiz, x);  
                if (predecessor == NULL) printf("erro");
                else printf("%d", predecessor->info);
                printf("\n");  
            break;

            case 4: //máximo (imprimindo pelo endereco do nó)
                maximo = max(a->raiz);  
                printf("%d", maximo->info);
                printf("\n");                  
            break;

            case 5: //mínimo (imprimindo pelo endereco do nó)
                minimo = min(a->raiz); 
                printf("%d", minimo->info);
                printf("\n");  
            break;

            case 6: //pré-ordem (imprimindo dentro da funcao)
                preOrdem(a->raiz);
                printf("\n");  
            break;

            case 7: //em-ordem (imprimindo dentro da funcao)
                emOrdem(a->raiz);
                printf("\n");  
            break;

            case 8: //pós-ordem (imprimindo dentro da funcao)
                posOrdem(a->raiz);
                printf("\n");  
            break;

            default:
                printf ("Valor de 'o' invalido!\n");
                return 0;
        }       
    }
    destruirArvore(a->raiz);
    return 0;
}