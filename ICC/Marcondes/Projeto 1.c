#include <stdio.h>
#include <math.h>
#define MAX_L 11
#define MAX_C 5

    void cheque_paciente(float a[][MAX_C], int m, int n){
        float d;
        for(int i = m; i >= 0; i--){
            for(int j = 0; j < MAX_C - 1; j ++){
                d =+ (a[i][j] - a[i - 1][j]) * (a[i][j] - a[i - 1][j]);
            }
        }
        d = sqrt(d);
        a[m][MAX_C-1] = d;
    }
   
    void imprima_tabela(){
    }

    int main(){
        float sintomas;
        float tabela[MAX_L][MAX_C] = {{0.5, 0.3, 0.2, 0.5,  1.0}, 
                                      {2.0, 0.8, 3.0, 5.2, -1.0},
                                      {1.8, 2.1, 0.7, 0.9,  1.0}};
        int m, n;
        for(m = 3; m < MAX_L; m++){
            for(n = 0; n < MAX_C - 1; n++){
                scanf("%f", &sintomas);
                while(sintomas < 3 || sintomas > 7){
                    printf("Valor Inválido, este deve estar no intervalo [3,7]\n");
                    scanf("%f", &sintomas);
                }
                tabela[m][n] = sintomas;
                cheque_paciente(tabela, m, n);
                printf("%.1f\n", tabela[m][MAX_C-1]); 
            }
        }   
    return 0;
    }