#include <stdio.h>
#include <math.h>
int main(){
    float a, b, c, delta, raiz_1, raiz_2;
    scanf("%f", &a);
    scanf("%f", &b);
    scanf("%f", &c);
    delta = (pow (b, 2)) - (4 * a * c);
    if(delta < 0){
        printf ("Delta Negativo");
        return 0;
        }
    raiz_1=(-b+sqrt(delta))/(2*a);
    raiz_2=(-b-sqrt(delta))/(2*a);
    printf("%.1f\n%.1f", raiz_1, raiz_2);
return 0;
}
