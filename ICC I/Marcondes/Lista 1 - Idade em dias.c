#include <stdio.h>
int main(){
    int idade, dias, meses, anos;
    scanf("%d", &idade);
    anos=idade/365;
    meses= (idade%365)/30;
    dias=(idade%365)%30;
    printf("%d ano(s)\n%d mes(es)\n%d dia(s)\n", anos, meses, dias);
return 0;
}
