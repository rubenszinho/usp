#include <stdio.h>

int main(){
    int Q, P, D, TOTAL;
    for( ; ; ){
        scanf("%d", &Q);
        if(Q == 0)
            return 0;
        scanf("%d", &D);
        scanf("%d", &P);
        TOTAL = (Q * D * P) /(P - Q);
        if(TOTAL <= 1)
            printf("%d pagina\n", TOTAL);
        else
            printf("%d paginas\n", TOTAL);
    }
}
