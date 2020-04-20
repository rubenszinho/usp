#include <stdio.h> // LER DESCOBRIR OS DIVISORES DO NUMERO
int main(){
int x, c;
scanf("%d",&x);
printf("Os divisores de %d sao:\n",x);
for(c = 1;c <= x; c ++){
    if(x%c==0)
    printf("%d\n",c);
}
return 0;}
