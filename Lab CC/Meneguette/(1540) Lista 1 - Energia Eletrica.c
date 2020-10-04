#include <stdio.h>
int main(){

    long long int n, aux, a, b, c, d, anos, novocresce, inteiro, resto; //aux para criar contagem com n repeticoes
    double cresce;
    scanf ("%lld", &n);
    for (aux = 1; aux <= n; aux ++){
        scanf ("%lld%lld%lld%lld", &a, &b, &c, &d);
        anos = c - a;
        cresce = (double)(d - b)/anos;             //cresce == crescimento anual
        novocresce = (long long int)(cresce * 100); //novocresce, resto e inteiro foram criadas para que o valor seja expresso com virgula
        inteiro = (long long int)cresce * 100;
        resto = ((novocresce - inteiro) % 100);
        printf ("%0.2lld,%0.2lld\n", inteiro / 100, resto);
    }
    return(0);
}