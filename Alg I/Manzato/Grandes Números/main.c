#include <stdio.h>
#include <string.h>
#include "bignum.h"
#include "list.h"

#define BUFFER_SIZE 100000

// Usando convenção do BSD (http://man.openbsd.org/sysexits)
#define EX_DATAERR 65
#define EX_OSERR 71

#define INVALID_OPERATION EX_DATAERR
#define MEMORY_ERROR EX_OSERR

typedef struct _entrada {
    char *tipo;
    char *num1;
    char *num2;
} entrada;

// Recebe do usuário inputs em buffers estáticos, aloca memória para eles e os copia. O(n)
entrada *receber_entrada(FILE *stream) {
    char buffer[BUFFER_SIZE];
    fgets(buffer, BUFFER_SIZE, stream);
    char tipo_buffer[BUFFER_SIZE];
    char num1_buffer[BUFFER_SIZE];
    char num2_buffer[BUFFER_SIZE];
    sscanf(buffer, "%s %s %s", tipo_buffer, num1_buffer, num2_buffer);

    entrada *out = malloc(sizeof(entrada));
    out->tipo = malloc(sizeof(char)*(strlen(tipo_buffer)+1));
    strcpy(out->tipo, tipo_buffer);
    out->num1 = malloc(sizeof(char)*(strlen(num1_buffer)+1));
    strcpy(out->num1, num1_buffer);
    out->num2 = malloc(sizeof(char)*(strlen(num2_buffer)+1));
    strcpy(out->num2, num2_buffer);

    return out;
}

// Desaloca todos os campos da estrutura entrada dado ponteiro, e muda o ponteiro dado para NULL. O(1)
void destruir_entrada(entrada** in) {
    free((*in)->tipo);
    free((*in)->num1);
    free((*in)->num2);
    free(*in);
    *in = NULL;
}

int main() {
    // Quantas vezes rodar
    int n;

    char buffer[BUFFER_SIZE];
    fgets(buffer, BUFFER_SIZE, stdin);
    sscanf(buffer, "%d", &n);

    // Iterar para cada caso teste do usuário
    for (int i = 1; i <= n; i++) {
        entrada *caso = receber_entrada(stdin);

        // Caso sum
        if (strcmp(caso->tipo, "sum") == 0) {
            bignum *num1 = bignum_create(caso->num1);
            bignum *num2 = bignum_create(caso->num2);
            destruir_entrada(&caso);
            if (num1 == NULL || num2 == NULL) {
                fprintf(stderr, "Erro ao alocar número\n");
                return MEMORY_ERROR;
            }
            bignum *sum = bignum_sum(num1, num2);
            bignum_destroy(&num1);
            bignum_destroy(&num2);
            if (sum == NULL) {
                fprintf(stderr, "Erro ao alocar soma de números\n");
                return MEMORY_ERROR;
            }
            printf("Resultado %d: ", i);
            bignum_print(sum);
            printf("\n");
            bignum_destroy(&sum);
        }

        // Caso big
        else if (strcmp(caso->tipo, "big") == 0) {
            bignum *num1 = bignum_create(caso->num1);
            bignum *num2 = bignum_create(caso->num2);
            destruir_entrada(&caso);
            if (num1 == NULL || num2 == NULL) {
                fprintf(stderr, "Erro ao alocar número\n");
                return MEMORY_ERROR;
            }
            int resultado = bignum_cmp(num1, num2, 0);
            bignum_destroy(&num1);
            bignum_destroy(&num2);
            printf("Resultado %d: ", i);
            if (resultado > 0) printf("1");
            else printf("0");
            printf("\n");
        }

        // Caso sml
        else if (strcmp(caso->tipo, "sml") == 0) {
            bignum *num1 = bignum_create(caso->num1);
            bignum *num2 = bignum_create(caso->num2);
            destruir_entrada(&caso);
            if (num1 == NULL || num2 == NULL) {
                fprintf(stderr, "Erro ao alocar número\n");
                return MEMORY_ERROR;
            }
            int resultado = bignum_cmp(num1, num2, 0);
            bignum_destroy(&num1);
            bignum_destroy(&num2);
            printf("Resultado %d: ", i);
            if (resultado < 0) printf("1");
            else printf("0");
            printf("\n");
        }
        
        // Caso eql
        else if (strcmp(caso->tipo, "eql") == 0) {
            bignum *num1 = bignum_create(caso->num1);
            bignum *num2 = bignum_create(caso->num2);
            destruir_entrada(&caso);
            if (num1 == NULL || num2 == NULL) {
                fprintf(stderr, "Erro ao alocar número\n");
                return MEMORY_ERROR;
            }
            int resultado = bignum_cmp(num1, num2, 0);
            bignum_destroy(&num1);
            bignum_destroy(&num2);
            printf("Resultado %d: ", i);
            if (resultado == 0) printf("1");
            else printf("0");
            printf("\n");
        }

        // Caso inválido
        else {
            destruir_entrada(&caso);
            fprintf(stderr, "Operação inválida. Use sum, big, sml ou eql.\n");
            return INVALID_OPERATION;
        }
    }
}
