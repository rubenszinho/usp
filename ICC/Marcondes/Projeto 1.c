#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <float.h>

int main(){
    int max_i, max_p;
    printf("\\___________Projeto 1 de ICC___________/\n\n");
 
//Quantidade: Pacientes.
    printf("Para efeitos estatisticos relevantes, sera necessario que voce predefina dados de 10 pacientes !!!\n");
    printf("Portanto, defina a quantidade de pacientes, que devera ser 11 obrigatoriamente:\n");
    scanf("%d", &max_p);
    system("cls");
    while(max_p != 11){
        printf("Entrada invalida, escolha uma quantidade de pacientes igual a 11:\n");
        scanf("%d", &max_p);
        system("cls");
    }

//Quantidade: Exames ou Sintomas.
    printf("Agora, defina a quantidade de indicadores, que devera ser de no minimo 3 e no maximo 7:\n");
    scanf("%d", &max_i);
    system("cls");
    while(max_i < 3 || max_i > 7){
        printf("Entrada invalida, escolha uma quantidade de indicadores que nao seja menor que 3 ou nao seja maior que 7:\n");
        scanf("%d", &max_i);
        system("cls");
    }

//Preenchendo Tabela de Histórico.
    float tabela[max_p][max_i + 1];
    for(int m = 0; m < max_p - 1; m ++){
        printf("Digite os %d exames/sintomas do Paciente %d e por fim o indice de saudavel/doente (1.0/-1.0):\n", max_i, m + 1);
        for(int n = 0; n < max_i + 1; n ++){ 
            scanf("%f", &tabela[m][n]);
            system("cls");
            if (n == max_i){
                while(tabela[m][n] != 1 && tabela[m][n] != -1){
                    printf("Entrada invalida, o indice so pode assumir valores 1.0 e -1.0. Digite novamente:\n");
                    scanf("%f", &tabela[m][n]);
                    system("cls");
                }
            }
        }
    }
    printf("Agora, digite os %d exames/sintomas do Paciente 11, e o programa ira estipular a chance deste estar\nsaudavel/doente (1.0/-1.0) atraves do historico fornecido:\n", max_i);
    for(int m = max_p - 1, n = 0 ; n < max_i; n ++){     
        scanf("%f", &tabela[m][n]);
        system("cls");
    }

//Imprimindo Tabela de Histórico para o usuário.
    printf("Ate entao, antes da previsao, seus dados fornecidos foram organizados da seguinte forma:\n");
    for(int m = 0; m < max_p ; m ++){
        for(int n = 0; n < max_i + 1; n ++){
            if(m == max_p - 1 && n == max_i)
                break;
            printf("%.1f  ", tabela[m][n]);

		}
		printf("\n");
	}
    printf("\n(Pressione qualquer tecla para continuar)");
    getch();
    system("cls");

//Calculando Distancia Euclidiana.
    float d , d_anterior = FLT_MAX;
    for(int m = 0 ; m < max_p - 1; m ++){
        d = 0.0;
        for(int n = 0; n < max_i; n ++){           
            d += pow((tabela[m][n] - tabela[10][n]), 2);
        }
        d = sqrt(d);
        if(d <= d_anterior){
            tabela[10][max_i] = tabela[m][max_i];
            d_anterior = d;
        }
    }

//Imprimindo Tabela de Histórico com o dado de tendencia do Paciente 11.
    printf("Tabela completa com o indice de tendencia do Paciente 11 estipulado:\n");
        for(int m = 0; m < max_p ; m ++){
            for(int n = 0; n < max_i + 1; n ++){
                printf("%.1f  ", tabela[m][n]);
            }
            printf("\n");
        }
getch();
return 0;
}
