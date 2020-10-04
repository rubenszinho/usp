#include <stdio.h>
#define pi 3.14159
int main(){
    float a, b, c, triangulo, circulo, trapezio, quadrado, retangulo;
    scanf ("%f %f %f", &a, &b, &c);
    triangulo = (a*c)/2;
    circulo = pi*c*c;
    trapezio = (a+b)*c/2;
    quadrado = b*b;
    retangulo = a*b;

    printf("%.3f \n%.3f \n%.3f \n%.3f \n%.3f", triangulo, circulo, trapezio, quadrado, retangulo);
    return 0;
    }
