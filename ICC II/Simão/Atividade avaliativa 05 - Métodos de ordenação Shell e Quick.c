#include <stdio.h>
#include <stdlib.h>

void shell(int *vetor, int tamanho, unsigned long int *num_operacoes);
void quick(int *v, int c, int f, unsigned long int *cmp_quick, unsigned long int *swp_quick);

int main()
{
    int tamanho;
    scanf("%d", &tamanho);

    int *vetor = (int *) calloc(tamanho, sizeof(int));
    // Alocação e leitura do vetor
    for (int i = 0; i < tamanho; i++)
    {
        scanf("%d", &vetor[i]);
    }

    // Laço para trabalhar com os subvetores
    for (int i = 1; i <= tamanho; i++)
    {
        // ------- lidando com o shell -------

        // Alocando memória para o subvetor
        int *vetor_shell = (int *) calloc(i, sizeof(int));
        // Preenchendo-o com os indices de 0 até o seu tamanho - 1
        // a partir do vetor originalmente lido do usuário
        for (int j = 0; j < i; j++)
        {
            vetor_shell[j] = vetor[j];
        }
        // Obtendo o numero de operações realizadas pelo shell,
        // que foi implementado a partir do endereço de uma
        // variável do programa principal.
        unsigned long int op_shell = 0;
        shell(vetor_shell, i, &op_shell);


        // ------- lidando com o quick -------

        // Alocando memória para o subvetor que o quick ordenará
        // (Não podemos usar o mesmo vetor, pois ele já terá sido
        // ordenado pelo shell)
        int *vetor_quick = (int *) calloc(i, sizeof(int));
        // preenchendo-o...
        for (int j = 0; j < i; j++)
        {
            vetor_quick[j] = vetor[j];
        }
        // Obtendo o numero de comparações e de trocas, para somá-los
        // e obter o número de operações.
        unsigned long int cmp_quick = 0, swp_quick = 0;
        quick(vetor_quick, 0, i - 1, &cmp_quick, &swp_quick);
        unsigned long int op_quick = cmp_quick + swp_quick;

        // Comparando qual método teve o menor número de operações em cada
        // subvetor, e imprimindo a respectiva saída:
        // S = Shell com menos operações. Q = Quick com menos operações
        // Hífen ( - ) = Número de comparações igual.
        if (op_shell < op_quick)
        {
            printf("S");
        }
        else if (op_quick < op_shell)
        {
            printf("Q");
        }
        else
        {
            printf("-");
        }
        printf(" ");

        // Liberando os dois subvetores alocados
        free(vetor_shell);
        free(vetor_quick);
    }

    free(vetor);
    printf("\n");

    return 0;
}

void shell(int *vetor, int tamanho, unsigned long int *num_operacoes)
{
    int gap = 1;
    while (gap <= tamanho)
    {
        gap *= 2;
    }
    gap = (gap / 2) - 1;
    // Iniciando o valor de gap da forma 2^k - 1

    // Loop diminuindo cada vez pela metade o valor do gap, até
    // chegar em gap == 0, uma iteração após gap == 1, que é o
    // insertion per se. (1/2 == 0).
    while (gap > 0)
    {
        int j;
        for (int k = 0; k < gap; k++)
        {
            for (int i = k + gap; i < tamanho; i += gap)
            {
                int x = vetor[i];
                (*num_operacoes)++;

                j = i - gap;

                // laço para conseguir contar as operações com o conceito
                // de curto-circuito. A comparação envolvendo os elementos
                // do vetor que deve ser contada, só será executada se
                // a primeira condição for atendida.
                while (1)
                {
                    if (j >= 0)
                    {
                        (*num_operacoes)++;
                        if (vetor[j] > x)
                        {
                            vetor[j + gap] = vetor[j];
                            (*num_operacoes)++;
                            j -= gap;
                        }
                        else
                        {
                            break;
                        }
                    }
                    else
                    {
                        break;
                    }
                }

                vetor[j + gap] = x;
                (*num_operacoes)++;
            }
        }
        gap /= 2;
    }
}

void quick(int *v, int c, int f, unsigned long int *cmp_quick, unsigned long int *swp_quick)
{
    if (c >= f)
    {
        return;
    }
    int m = (c + f) / 2;
    int pivo = v[m];
    (*swp_quick)++;

    int i = c;
    int j = f;

    while (1)
    {
        // Uma comparação para entrar
        (*cmp_quick)++;
        while (v[i] < pivo)
        {
            i++;
            (*cmp_quick)++;
            // sempre que fizer uma vez, fará mais uma comparação antes de prosseguir
        }

        (*cmp_quick)++;
        while (v[j] > pivo)
        {
            j--;
            (*cmp_quick)++;
        }

        if (j <= i)
        {
            break;
        }

        int tmp = v[i];
        v[i] = v[j];
        v[j] = tmp;
        (*swp_quick) += 3;
        // contabilizando a troca como 3 comparações,
        // em virtude da variáveltemporária
        i++;
        j--;
    }

    quick(v, c, j, cmp_quick, swp_quick);
    quick(v, j + 1, f, cmp_quick, swp_quick);
}