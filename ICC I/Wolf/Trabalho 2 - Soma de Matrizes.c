#include <stdio.h>
#include <stdlib.h>

float **aloc (int m, int n);
float **liberar (int m, int n, float **v);
int main(){
    float **soma, **matA, **matB;
    int x, y;
    int i, j;
    printf ("Defina as dimensoes das matrizes(separe por espaco):\n");
    scanf ("%d %d", &x, &y);
    matA = aloc(x, y);
    matB = aloc(x, y);                                      //ATRIBUINDO AS MESMAS DIMENSOES PARA CADA MATRIZ
    soma = aloc(x, y);
    for (i = 0; i < x; i ++){
        for (j = 0; j < y; j ++){
            printf ("Defina o elemento (%d,%d) da matriz A: ", i + 1, j + 1);
            scanf ("%f", &matA[i][j]);                      //INSERINDO OS VALORES DE CADA ELEMENTO DA MATRIZ A
        }
    }
    for (i = 0; i < x; i ++){
        for (j = 0; j < y; j ++){
            printf ("Defina o elemento (%d,%d) da matriz B: ", i + 1, j + 1);
            scanf ("%f", &matB[i][j]);                      //INSERINDO OS VALORES DE CADA ELEMENTO DA MATRIZ B
        }
    }
    for (i = 0; i < x; i ++){
        for (j = 0; j < y; j ++){
            soma[i][j] = matA[i][j] + matB[i][j];           //SOMANDO AS MATRIZES
        }
    }
    printf ("\nMatriz soma: \n");
    for (i = 0; i < x; i ++){
        for (j = 0; j < y; j ++){
            printf ("%.2f ", soma[i][j]);
        }
    getch();
    }
    liberar(x, y, matA);
    liberar(x, y, matB);                                    //LIBERANDO MEMORIA
    liberar(x, y, soma);
    return 0;
}

float **aloc (int m, int n){
    float **v;
    int i;
    if (m < 1 || n < 1){
    printf ("Parametro invalido\n");
    return NULL;
    }
    v = (float **) malloc(m * sizeof(float*));
    if(v == NULL){
        printf("Memoria insuficiente");
        return NULL;
    }
    for (i = 0; i < m; i ++){
        v[i]=(float*) malloc(n * sizeof(float));
        if (v[i] == NULL){
        printf("Memoria insuficiente");
        return NULL;
        }
    }
    return v;
}

float **liberar (int m, int n, float **v){
    int i;
    if (v == NULL){
        return NULL;
    }
    if (m < 1 || n < 1){
        printf("Parametro invalido");
        return v;
    }
    for (i = 0; i < m; i ++){
        free (v[i]);
    }
    free (v);
    return NULL;
}
