/*Faça uma função que leia uma String representando uma data no formato DD/MM/YYYY.
 A sua função deve retornar o número de dias. Considere sempre que um mês tem 31 dias 
 e um ano tem 365 dias.*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TAM 11
int main(){
    char buffer[TAM];
    fgets(buffer, TAM, stdin);
    buffer[strcspn(buffer, "\n")] = 0;
    int tam = strlen(buffer);
    char *str = malloc(sizeof(char)*(tam+1));
    int ano, mes, dia, data, j, i;
    strcpy(str, buffer);
    for (i = j = 0; i < tam; i ++) 
       if (str[i] != '/') 
          str[j ++] = str[i]; 
    str[j] = '\0'; 
    data = atoi(str);
    dia = data / 1000000;
    mes = data / 10000;
    mes = mes % 100; 
    ano = data % 10000;
    dia += (ano*365) + (mes*31);
    printf("%d", dia);  
return 0;
}