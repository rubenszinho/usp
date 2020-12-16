#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lista.h"

int main(){
  int n, j;
  char opcao;
  lista_t *l = cria();
  scanf("%c", &opcao);
  while(opcao != 'f'){
    if(opcao == 'i'){
      scanf("%d %d", &n, &j);
      insira(l, n, j);
    }
    else if (opcao == 'r'){
      scanf("%d", &n);
      remova(l, n);
    }
    scanf("%c", &opcao);
  }
  imprima(l);
  libere(l);
return 0;
}