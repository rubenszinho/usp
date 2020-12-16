#include <stdio.h>

int main()
{
    int horas, minutos, segundos, totalsegundos;
    printf("Digite no modelo tradicional");
    printf("\nHoras:");
    scanf("%d", &horas);
    printf("Minutos:");
    scanf("%d", &minutos);
    printf("Segundos:");
    scanf("%d", &segundos);

    minutos = (minutos*60);
    horas = (horas*3600);
    totalsegundos = (horas + minutos + segundos);

    horas = totalsegundos/10000;
    minutos = (totalsegundos%10000)/100;
    segundos = (totalsegundos%10000)%100;


    printf("%dh %dmin %dseg convertido para o modelo decimal", &horas, &minutos, &segundos );
return 0;
}
