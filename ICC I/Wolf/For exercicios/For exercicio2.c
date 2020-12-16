#include <stdio.h> // CALCULAR S = 1/1+3/2+5/3+7/4...99/50
int main(){
double a = 1, b = 1,c ,fracao = 1;
for(c = 1;c < 50;c++){
    fracao = fracao + (a+2)/(b+1);
    a = a + 2;
    b = b + 1;
}
printf("S = %lf", fracao);
return 0;
}
