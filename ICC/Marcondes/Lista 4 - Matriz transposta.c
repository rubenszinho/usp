/*Leia uma matriz 2x3 de inteiros e imprimir a matriz transposta.
Exemplo: Entrada: m[0][0] = 4 m[0][1] = 2 m[0][2] = 1 m[1][0] = 5 m[1][1] = 4 m[1][2] = 2
Saída:
4 5 2 4 1 2
OBS1: não usar uma matriz auxiliar para a transposta.*/ 

#include <stdio.h>
#define MAX_L 2
#define MAX_C 3
int main(){
    int matriz[MAX_L][MAX_C], transposta[MAX_C][MAX_L], i, j;
    for (i = 0; i < MAX_L; ++i) {
        for (j = 0; j < MAX_C; ++j) {
            scanf("%d", &matriz[i][j]);
        }
    }
    for (i = 0; i < MAX_L; ++i) {
        for (j = 0; j < MAX_C; ++j) {
            transposta[j][i] = matriz[i][j];
        }
    }

    for (i = 0; i < MAX_C; ++i) {
        for (j = 0; j < MAX_L; ++j) {
            printf("%d ", transposta[i][j]);
            if(j == MAX_L - 1)
                printf("\n");
        }
    }
    return 0;
}
