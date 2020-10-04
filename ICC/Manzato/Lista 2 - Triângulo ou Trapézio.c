#include <stdio.h>
    int main (){
        double A, B, C, AREA_TRA, PERI_TRI;
        scanf("%lf %lf %lf", &A, &B, &C);
        if (A >= B + C || B >= A + C || C >= B + A){
            AREA_TRA = ((A + B)* C) / 2;
            printf("Area = %.1lf", AREA_TRA );
        }
        else{
            PERI_TRI = A + B + C;
            printf("Perimetro = %.1lf", PERI_TRI );
        }
    return 0;
    }
