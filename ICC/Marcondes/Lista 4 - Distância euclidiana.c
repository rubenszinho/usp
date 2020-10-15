//Leia dois vetores de floats de tamanho 3 cada, representando as coordenadas (x,y,z). Em seguida, imprima a distância euclidiana entre as duas coordenadas (use duas.

//OBS: utilizar estruturas de repetição para o cálculo da distância euclidiana.

#include <stdio.h>
#include <math.h>

    int main(){
        float d = 0;
        float v1[3], v2[3];
        //vetor 1
        for (int m = 0; m< 3; m++){
            scanf("%f", &v1[m]);  
        }

        //vetor 2
        for (int m = 0; m < 3; m++){
            scanf("%f", &v2[m]);
        }

        //distancia euclidiana
        for (int i = 0; i < 3; i++){           
            d += pow((v1[i] - v2[i]), 2);
        }
        d = sqrt(d);
        printf("%f", d);
    return 0;
    }
    