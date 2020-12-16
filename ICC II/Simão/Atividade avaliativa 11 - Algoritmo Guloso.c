#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *move(char **reads, char *newstring, int n){
    char *result;

    if(reads[0] == NULL){
        reads[0] = newstring;
        result = reads[0];
    }
    else{
        int i = 0;
        char *temp1, *temp2;
        temp1 = reads[i];
        reads[i] = newstring;
        i++;
    
        while(i<n){
            if(reads[i] == NULL){
                reads[i] = temp1;
                result = reads[i];
                break;
            }
            else{
                temp2 = reads[i];
                reads[i] = temp1;
                temp1 = temp2;
                result = reads[i];
                i++;
            }
        }
    }

    return result;
}

char *insercao(int maior, char **reads, int p1, int p2, int local, int n){
    if(reads == NULL) return NULL;

    char *temp = (char *) malloc ((strlen(reads[p1]) + strlen(reads[p2]) + 1) * sizeof(char));

    //se igual a 0, significa que ira concatenar
    if(maior == 0){
        //copia pra uma string auxiliar
        strcpy(temp, reads[p1]);
        strcat(temp, reads[p2]);

        //libera as strings usadas
        free(reads[p1]);
        reads[p1] = NULL;
        free(reads[p2]);
        reads[p2] = NULL;
    }
    //significa que eh substring
    else if(local == -1){
        strcpy(temp, reads[p1]);
        free(reads[p1]);
        reads[p1] = NULL;
        
        free(reads[p2]);
        reads[p2] = NULL;
    }
    //aglutina a nova string no final da outra
    else{
        strcpy(temp, reads[p1]);
        strcpy(&temp[local], reads[p2]);

        free(reads[p1]);
        reads[p1] = NULL;
        
        //libera a segunda string
        free(reads[p2]);
        reads[p2] = NULL;
    }
    //move a nova string pro comeco
    return move(reads, temp, n);
}

char *permuta(char **reads, int n){
    if(reads == NULL) return NULL;

    int i, j, maior = -1, over = 0, pi, pj, temp, local;

    for(i=0; i<n; i++){
        if(reads[i] == NULL) continue;

        for(j=0; j<n; j++){
            if(reads[j] == NULL) continue;

            if(i == j) continue;

            over = 0;

            //caso reads[j] seja substring de reads[i]
            char *busca = strstr(reads[i], reads[j]);
            if(busca != NULL){
                over = strlen(reads[j]);
                temp = -1;
            }
            //caso nao seja
            else{
                int k, tami = strlen(reads[i]), tamj = strlen(reads[j]);

                if(tami >= tamj){
                    k = (tami - tamj);
                }
                else{
                    k = 0;
                }
                
                //faz a busca
                while(k < tami){
                    //procura pelo pedaco de reads[j] em reads[i]
                    //faz as comparacoes caso a caso
                    //vai "deslocando" a palavra e comparando as partes
                    over = strncmp(&reads[i][k], reads[j], (tami - k));

                    //temp indica onde havera a substituicao
                    temp = k;

                    //se igual a 0, entao nao foi encontrado e sera concatenado
                    //se diferente de 0, sera aglutinado no final
                    if(over == 0){
                        over = strlen(&reads[i][k]);
                        break;
                    }
                    else{
                        over = 0;
                    }
                    
                    k++;
                }
            }

            //salva os as informacoes do maior overlap encontrado
            if(over > maior){
                maior = over;

                pi = i;
                pj = j;
                local = temp;
            }
        }
    }

    //realiza a insercao da nova string
    return insercao(maior, reads, pi, pj, local, n);
}

int main(){
    int i, n;
    char word[2048], **reads, *result;

    scanf("%d", &n);
    reads = (char **) malloc (n * sizeof(char *));

    for(i=0; i<n; i++){
        scanf(" %s", word);
        
        //aloca o espaco necessario no "dicionario"
        reads[i] = (char *) malloc ((strlen(word)+1) * sizeof(char));
        
        //copia a palavra pro "dicionario"
        strcpy(reads[i], word);
    }

    for(i=0; i<n-1; i++){
        //faz a combinacao de todas as palavras
        result = permuta(reads, n);
    }

    //imprime o resultado
    printf("%s\n", result);

    for(i=0; i<n; i++){
        if(reads[i] != NULL)
        free(reads[i]);
    }
    free(reads);

    return 0;
}