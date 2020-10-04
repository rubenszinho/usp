#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main()
{

    char str1[1000], str2[1000], str3[1000];
    FILE *arq_1, *arq_2;


    //Lendo arquivo1 e arquivo2
    if ((arq_1 = fopen("arquivo1.txt", "r")) == NULL || (arq_2 = fopen("arquivo2.txt", "r")) == NULL)
    {
        printf("Erro ao abrir os arquivos");
    }
    while(!feof(arq_1)){
        fscanf(arq_1, "%s", str1);
        while(!feof(arq_2)){
            fscanf(arq_2, "%s", str2);
            if(strcmp(str1, str2) == 0)
            {
                if(strstr(str3, str1)== NULL)
                {
                    printf("%s\n", str1);
                    strcat(str3,str1);

                }
            }
        }
        fseek(arq_2, 0, SEEK_SET);
    }



    fclose(arq_1);
    fclose(arq_2);
}
