#include <stdio.h>
int main(){
    int A, B, C, D;
    do{
    scanf("%1d %1d %1d\n", &A, &B, &C);
    D=(A*B)*C/100;
    printf("%d\n", D);
    }while(A != 0);
}
