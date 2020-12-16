#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* troqueStr(const char* s, const char* strIncorreta, const char* strCorreta){
    char* correcao;
    int i, cont = 0;
    int strCorretaTam = strlen(strCorreta);
    int strIncorretaTam = strlen(strIncorreta);

    //Laco para indentificar as strings indesejadas
    for (i = 0; s[i] != '\0'; i++){
        if (strstr(&s[i], strIncorreta) == &s[i]){
            cont++;
            i = strIncorretaTam - 1 + i;
        }
    }

    //Alocar espaco suficiente para a string que sera gerada apos a correcao
    correcao = (char*)malloc(i + cont * (strCorretaTam - strIncorretaTam) + 100);
    i = 0;
    while (*s){


        //Laco para efetuar a correcao
        if (strstr(s, strIncorreta) == s){
            strcpy(&correcao[i], strCorreta);
            i = strCorretaTam + i;
            s = strIncorretaTam + s;
        }
        else
            correcao[i ++] = *s ++;
    }
    correcao[i] = '\0';
    return correcao;
}

int main(){
    char str[100];
    char incorreta[20];
    char correta[20];
    char* correcao = NULL;

    fgets(str, 100, stdin);
    fgets(incorreta, 20, stdin);
    fgets(correta, 20, stdin);
    correcao = troqueStr(str, incorreta, correta);
    printf("%s\n", correcao);
    free(correcao);
    return 0;
}
