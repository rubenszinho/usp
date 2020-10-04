#include <stdio.h>
int main(){
    double salario, reajuste, n_salario, p_reajuste;
    scanf("%lf", &salario);
    if(salario <= 400.00){
        p_reajuste = 0.15;
        n_salario = salario + (salario * p_reajuste);
        reajuste = n_salario - salario;
        p_reajuste = p_reajuste * 100;

        printf("Novo salario: %.2lf\nReajuste ganho: %.2lf\nEm percentual: %.0lf %%", n_salario, reajuste, p_reajuste);
        }
    else if(salario <= 800.00 && salario >= 400.01){
        p_reajuste = 0.12;
        n_salario = salario + (salario * p_reajuste);
        reajuste = n_salario - salario;
        p_reajuste = p_reajuste * 100;

        printf("Novo salario: %.2lf\nReajuste ganho: %.2lf\nEm percentual: %.0lf %%", n_salario, reajuste, p_reajuste);
        }
    else if(salario <= 1200.00 && salario >= 800.01){
        p_reajuste = 0.10;
        n_salario = salario + (salario * p_reajuste);
        reajuste = n_salario - salario;
        p_reajuste = p_reajuste * 100;

        printf("Novo salario: %.2lf\nReajuste ganho: %.2lf\nEm percentual: %.0lf %%", n_salario, reajuste, p_reajuste);
        }
    else if(salario <= 2000.00 && salario >= 1200.01){
        p_reajuste = 0.07;
        n_salario = salario + (salario * p_reajuste);
        reajuste = n_salario - salario;
        p_reajuste = p_reajuste * 100;

        printf("Novo salario: %.2lf\nReajuste ganho: %.2lf\nEm percentual: %.0lf %%", n_salario, reajuste, p_reajuste);
        }
    else if(salario > 2000.00){
        p_reajuste = 0.04;
        n_salario = salario + (salario * p_reajuste);
        reajuste = n_salario - salario;
        p_reajuste = p_reajuste * 100;

        printf("Novo salario: %.2lf\nReajuste ganho: %.2lf\nEm percentual: %.0lf %%", n_salario, reajuste, p_reajuste);
        }
    return 0;
}
