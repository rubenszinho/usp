#include <stdio.h>
int main(){
    double salario, vendas, comissao, fixo;
    scanf("%lf", &fixo);
    scanf("%lf", &vendas);
    comissao = (vendas*15)/100;
    salario = fixo + comissao;
    printf("%.2lf", salario);
return 0;
}
