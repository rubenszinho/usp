#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main() {
    srand(time(NULL));
    int a, b, c, d, ran_num;
    int sequencia[100], resposta[100];
    char ch;

    printf("Bem Vindo(a) ao Jogo da Memoria\n\n\n1. O programa apresenta uma sequencia de numeros de 0 a 9 por um periodo de tempo (~5 segs).\n\n2. O programa apaga a sequencia apresentada, e o usuario deve digitar a sequencia.\n\n3. Se a sequencia digitada estiver correta, o programa adiciona mais um numero na sequencia e o programa e volta a etapa'1', a sequencia comeca com 1 numero.\n\n4. Se a sequencia estiver errada, o jogo acaba e mostra a pontuacao do jogador, que corresponde a quantidade de numeros da maior sequencia correta digitada.\n\n5. Pontuacao maxima de 100 pontos\n\n\n");
    do{
        printf("\nPressione 's' para comecar.");
        ch=getch();
    }while(ch != 's' && ch != 'S');
    system("cls");
    ch = 0;

    for(a = 0; a < 100; a ++){
        ran_num = rand()%10;
        sequencia[a] = ran_num;
        printf("Sequencia para memorizar: ");
        for(b = 0; b <= a; b++)
            printf("%d ", sequencia[b]);
        Sleep(5000);
        system("cls");

        printf("Digitar sequencia: ");
        for(c = 0; c <= a; c ++)
            scanf("%1d", &resposta[c]);
        system("cls");

        for(d = 0; d <= a ; d ++)
            if(resposta[d] != sequencia[d]){
                printf("Sua pontuacao foi: %d !!!\n\n", a);
                do{
                    printf("\nPressione 's' para sair.");
                    ch=getch();
                }while(ch != 's' && ch != 'S');
                return 0;
            }
    }
printf("Parabens Alien !!\nVoce fez 100 pontos !!!\n\n");
do{
    printf("\nPressione 's' para sair.");
    ch=getch();
}while(ch != 's' && ch != 'S');
return 0;
}
