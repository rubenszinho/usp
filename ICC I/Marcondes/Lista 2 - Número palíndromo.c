#include <stdio.h>
    int numero_inverso(int num){
        int aux, num_i = 0;
        aux = num % 10;
        aux = aux * 100;
        num_i = aux + num_i;
        num = num / 10;
        aux = num % 10;
        aux = aux * 10;
        num_i = aux + num_i;
        num = num / 10;
        aux = num % 10;
        num_i = aux + num_i;
    return num_i;
    }

    int main(){
        int num;
        scanf("%d", &num);
        if(num > 99 && num < 1000 && numero_inverso(num) == num)
            printf("SIM");
        else if (num > 99 && num < 1000 && numero_inverso(num) != num)
            printf("NAO");
        else
            printf("INVALIDO");
    return 0;
    }
