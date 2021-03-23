#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *arq1;
    FILE *arq2;
    char c;

    arq1 = fopen("arquivo.txt", "r");
    arq2 = fopen("arquivo2.txt", "w");

        fscanf(arq1, "%c", &c);
        fprintf(arq2, "%c", c);
        
    fclose(arq1);
    fclose(arq2);

    return 0;
}
