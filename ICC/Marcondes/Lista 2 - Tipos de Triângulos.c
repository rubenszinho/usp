#include <stdio.h>
    int main(){
        double A, B, C, aux;
        scanf("%lf %lf %lf", &A, &B, &C);
        if(B > A){
            aux = B;
            B = A;
            A = aux;
        }
       if (C > A){
            aux = C;
            C = A;
            A = aux;
       }
        if (C > B){
            aux = C;
            C = B;
            B = aux;
        }
        if(A >= B + C){
            printf("NAO FORMA TRIANGULO\n");
            return 0;
        }
        if((A * A) == (B * B) + (C * C))
            printf("TRIANGULO RETANGULO\n");
        if((A * A) > (B * B) + (C * C))
            printf("TRIANGULO OBTUSANGULO\n");
        if((A * A) < (B * B) + (C * C))
            printf("TRIANGULO ACUTANGULO\n");
        if(A == B || C == B || A == C){
            if(A == B  && B == C && C == A)
                printf("TRIANGULO EQUILATERO\n");
            else
                printf("TRIANGULO ISOSCELES\n");
        }
        return 0;
    }
