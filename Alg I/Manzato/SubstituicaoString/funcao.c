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
    correcao = (char*)malloc(i + cont * (strCorretaTam - strIncorretaTam) + 1);
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
