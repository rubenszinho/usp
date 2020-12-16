#include <stdio.h>

//Inicialize a variável indicador em 0.
int main(){
    char vetor[30];
    char a[30];
    int indicador = 0;
    int i;

//Pegue uma expressão como entrada e armazene-a no vetor a.
    printf("Digite qualquer combinacao de chaves:\n");
    scanf("%s", a);
//Usando o loop for, verifique os “(” e “)” na expressão.
    for (i = 0; a[i] != '\0';i++){
        if (a[i] == '{'){
            vetor[indicador] = a[i];
            indicador++;
        }
        else if (a[i] == '}'){
            if (indicador == 0){
                printf("Errado\n");
                return 0;
            }
            else{
                indicador--;
            }
        }
    }
  	if (indicador == 0)
        printf("Correto\n");
    else
        printf("Errado\n");
    return 0;
}
