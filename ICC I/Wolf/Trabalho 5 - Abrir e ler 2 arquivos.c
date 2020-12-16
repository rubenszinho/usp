#include <stdio.h>

int main()
{
    FILE *arq_1;
    int i;
    char c[1000];

    if ((arq_1 = fopen("arquivo1.txt", "r"))== NULL)
    {
        printf("Erro abrindo arquivo.");
        return 0;
    }
    for(i=0; i<5; i++)
    {
        fscanf(arq_1, "%s", &c);
        printf("No arquivo esta escrito:\n%s", c);
    }
fclose(arq_1);
return 0;
}
