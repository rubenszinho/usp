#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *remover_letra(char *entrada, char letra) {
    char *saida = NULL;
    int tamanho_saida = 0;
    for(int i = 0; i < strlen(entrada); i++) {
        if (entrada[i] != letra) {
            tamanho_saida++;
            saida = realloc(saida, tamanho_saida*sizeof(char));
            saida[tamanho_saida-1] = entrada[i];
        }
    }
    saida = realloc(saida, (tamanho_saida+1)*sizeof(char));
    saida[tamanho_saida] = '\0';

    return (saida);
}


int main() {
    printf("%s\n", remover_letra("banana", 'a'));
}
