//Leia uma matriz 3x3 de inteiros. Imprima o determinante da matriz.
//OBS: use estruturas de repetição para cálculo do determinante.


#include <stdio.h>
int main(){
    int vet[3][3], i, j;
    int det = 0;
    for(i = 0;i < 3;i ++){
        for(j = 0;j < 3;j ++){
	        scanf("%d", &vet[i][j]);
        }
    }
    for(i=0;i < 3;i++){
        det += (vet[0][i]*(vet[1][(i+1)%3]*vet[2][(i+2)%3] - vet[1][(i+2)%3]*vet[2][(i+1)%3]));
    }
printf("%d\n",det);
return 0;
}
