#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fila.h"
    int main(){
        char nome[30];
        int idade;
        int agravante;             
        int n;
        void *p1, *p2, *p3, *p4;
        char funcao[10];
	    scanf("%d", &n);
        fila_t *p1 = criar();
	    fila_t *p2 = criar();
	    fila_t *p3 = criar();
	    fila_t *p4 = criar();
        for (int i = 0; i <= n; i++){
            scanf("%s %s %d %d", funcao, nome, &idade, &agravante);
            if (strcmp(funcao,"SAI") == 0){
			    if(isEmpty(p1) == 0){
				    remover(p1, nome);
				    printf("%s %d %d", nome, idade, agravante);
			    }
			    else if(isEmpty(p2) == 0){
				    remover(p2, nome);
			    	printf("%s %d %d", nome, idade, agravante);
			    }
			    else if(isEmpty(p3) == 0){
			    	remover(p3, nome);
			    	printf("%s %d %d", nome, idade, agravante);
		    	}
			    else if(isEmpty(p4) == 0){
			    	remover(p4, nome);
			    	printf("%s %d %d", nome, idade, agravante);
			    }
			    else
			    	printf("FILA VAZIA\n");
		    }
        
            if (strcmp(funcao,"ENTRA") == 0){
                if(idade >= 60 && agravante == 1)
                    inserir(p1, *nome);
                else if(agravante == 1)
                    inserir(p2, *nome);
                else if(idade >= 60)
                    inserir(p3, *nome);
                else
                    inserir(p4, *nome);                                  
	        }
        }
    destruir(p1);
	destruir(p2);
	destruir(p3);
	destruir(p4);
    return 0;
    }