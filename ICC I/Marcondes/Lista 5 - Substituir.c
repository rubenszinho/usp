#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAMANHO 100

char* troqueStr(const char* s, const char* str2, const char* str3){
    char* substituicao;
    int i, cont = 0;
    int str3Tam = strlen(str3);
    int str2Tam = strlen(str2);

    //Laco para indentificar as strings indesejadas
    for (i = 0; s[i] != '\0'; i++){
        if (strstr(&s[i], str2) == &s[i]){
            cont++;
            i = str2Tam - 1 + i;
        }
    }
    //Alocar espaco suficiente para a string que sera gerada apos a substituicao
    substituicao = (char*)malloc(i + cont * (str3Tam - str2Tam) + 1);
    i = 0;
    while (*s){
        //Laco para efetuar a substituicao
        if (strstr(s, str2) == s){
            strcpy(&substituicao[i], str3);
            i = str3Tam + i;
            s = str2Tam + s;
        }
        else
            substituicao[i ++] = *s ++;
    }
    substituicao[i] = '\0';
    return substituicao;
}
char *ler() {
	char buffer[TAMANHO];
	if (fgets(buffer, TAMANHO, stdin) == NULL) {
		return NULL;
	}
	char *string = malloc(sizeof(char)*strlen(buffer));
	buffer[strcspn(buffer, "\r")] = 0;
	strcpy(string, buffer);
	return string;
}

int main(){
		char *str1 = ler();
		char *str2 = ler();
		char *str3 = ler();
		char *substituicao = troqueStr(str1, str2, str3);
		free(str1);
		free(str2);
		free(str3);
	    printf("%s\n", substituicao);
	    free(substituicao);
	return 0;
}
