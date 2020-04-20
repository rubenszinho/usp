#include <stdio.h>  //DESCOBRIR OS QUADRADOS PERFEITOS DE 1 ATE 5000
int main(){
int x, resultado=1 ;
printf("Quadrados perfeitos de 1 ate 5000:", resultado);
for(x = 2; resultado <= 5000; x ++){
    printf("\n%d", resultado);
    resultado = (x*x);
}
return 0;}
