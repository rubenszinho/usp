#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void scanElements(int nElements);
void bubble(int nElements);
void selection(int nElements);

int *elements;

int main()
{
    char selectSort[10];
    int nElements;

    scanf("%s", selectSort);
    scanf("%d", &nElements);

    if (!strcmp(selectSort, "bolha"))
        bubble(nElements);

    else if (!strcmp(selectSort, "selecao"))
        selection(nElements);

    return 0;
}

void scanElements(int nElements)
{
    int i;
    elements = malloc(nElements * sizeof(int));

    for (i = 0; i < nElements; i++)
        scanf("%d", &elements[i]);
}

void bubble(int nElements)
{
    int i, aux, ultimaTroca = nElements, sentinela = 0;
    scanElements(nElements);

    while(ultimaTroca > 1){
        sentinela = 0;
        for(i = 1; i < ultimaTroca; i++){
            printf("C %d %d\n", (i-1), i);
            if(elements[i] < elements[i-1]){
                printf("T %d %d\n", i-1, i);
                aux = elements[i-1];
                elements[i-1] = elements[i];
                elements[i] = aux;
                sentinela = i;
            }
        }
        ultimaTroca = sentinela;
    }
    for (int i = 0; i < nElements; i++)
        printf("%d ", elements[i]);
}

void selection(int nElements)
{
    int atualPosition = 0, j, minorPosition = 0, aux;
    scanElements(nElements);

    while (atualPosition < nElements)
    {
        for (j = (atualPosition + 1); j < nElements; j++)
        {
            printf("C %d %d\n", minorPosition, j);
            if (elements[j] < elements[minorPosition])
                minorPosition = j;
        }

        if (elements[atualPosition] != elements[minorPosition])
        {
            aux = elements[atualPosition];
            elements[atualPosition] = elements[minorPosition];
            elements[minorPosition] = aux;
            printf("T %d %d\n", atualPosition, minorPosition);
        }
        atualPosition++;
        minorPosition = atualPosition;
    }

    for (int i = 0; i < nElements; i++)
        printf("%d ", elements[i]);
}
