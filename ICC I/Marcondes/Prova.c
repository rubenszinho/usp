#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *arq;
    arq = fopen("arquivo.txt", "w+");

    if(arq=NULL){
        printf("Erro ao abrir o arquivo!");
        exit(1);
    }

    fprintf(arq, "COMPUTADOR");
}
