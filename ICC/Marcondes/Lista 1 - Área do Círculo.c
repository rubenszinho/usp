#include <stdio.h>
int main(){
    const double pi = 3.14159;
    double raio;
    double area;
    scanf("%lf", &raio);
    area = raio*raio*pi;
    printf ("%.4lf", area);
    getchar();
return 0;
}
