#ifndef dict_h
#define dict_h

typedef struct no_t no;
typedef struct _dict dict;

//Aloca e inicializa um dict, o retornando
dict *dict_create();

//Retorna a cópia da string elemento
char *no_elem(no *in);

//Obter o elemento de uma dada chave em um dicionario
char *dict_get(dict *in, char *chave);

//Retorna a cópia da string chave
char *no_chave(no *in);

//Alterar o elemento de uma chave (ou criar se não exista) num dicionario
int dict_set(dict *in, char *key_in, char *value_in);

//Remover um nó do dicionario
int dict_unset(dict *in, char *chave); 

//Encontrar a primeira ocorrencia alfabetica de um caractere numa chave do dicionario
no *dict_no_primeiro_char(dict *in, char character);

//Retorna o proximo nó da ultima camada
no *proximo_no(no *current);

//Destruir o dicionário
void destroi_dict(dict **in);



#endif
