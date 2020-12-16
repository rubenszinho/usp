#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TAM 100

int main(){
    int ASCII[256];
    for(int i = 0; i < 256; i++) ASCII[i] = 0;

    char buffer[TAM];
    fgets(buffer, TAM, stdin);
    buffer[strcspn(buffer, "\n")] = 0;

    int str_len = strlen(buffer);
    char *str = (char *)malloc(sizeof(char)*(str_len+1));
    strcpy(str, buffer);

    for(int i = 0; i < str_len; i++){
        ASCII[(int)str[i]] = 1;
    }
    free(str);

    int count = 0;
    for(int i = 0; i < 256; i++) {
        if(ASCII[i] == 1) {
            count ++;
        }
    }

    printf("%d", count);
    return 0;
}