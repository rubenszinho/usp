#include <stdio.h>
//#include <string.h>
#include <stdlib.h>
#include "lista.h"
/*int main(){
  int chave, tempo = 0;
  char opcao;
  scanf("%c", opcao);
  if(strcmp (opcao, 'i') == 0){

  }
  else if(strcmp (opcao, 'j') == 0){

  }
  else{
    printf("Entrada invalida")
    return 0;
  }
}*/

int main(){
  lista_t *l = cria();

  insere(l, 5);
  insere(l, 2);
  insere(l, 3);
  insere(l, 7);
  insere(l, 8);
  imprimir(l);

  remover(l, 5);
  imprimir(l);

  remover(l, 8);
  imprimir(l);

  liberar(l);
  return 0;
}
