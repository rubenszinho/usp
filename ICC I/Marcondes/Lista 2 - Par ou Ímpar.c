#include <stdio.h>
    int main(){
        int num;
        scanf("%d", &num);
        if (num == 0 || num < 0)
            printf("INVALIDO");
        else if (num % 2 == 1)
            printf("IMPAR");
        else
            printf("PAR");
    return 0;
    }
