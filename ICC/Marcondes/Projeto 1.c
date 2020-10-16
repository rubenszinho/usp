#include <stdio.h>
#include <math.h>
#define MAX_L 11
int MAX_C;

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
        int m, n;
        float sintomas;
        scanf("%d", &MAX_C);
        float tabela[MAX_L][MAX_C];

    }