#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "bignum.h"
#include "list.h"

// Estrutura para armazenar os grandes números
struct _bignum {
    // Se é negativo (1) ou positivo (0)
    int negative;
    // Lista de dígitos
    list *digits;
};

// Função auxiliar (não pública)
// Verifica se o caractere é equivalente a um número 0-9
int is_num(char input) {
    if (input >= '0' && input <= '9') return 1;
    else return 0;
}

// Função auxiliar (não pública)
// Função para imprimir ints (no stdin), é passada como argumento para imprimir as listas
void printfunction(void *input) {
    printf("%d", *(int *)input);
}

// Dado uma string de caracteres representando um número, aloca e retorna ele na estrutura bignum
bignum *bignum_create(const char *input) {
    // Copiar string para evitar modificar
    char *in = malloc(sizeof(char)*(strlen(input)+1));
    // Caso a alocação falhe
    if (in == NULL) return NULL;
    strcpy(in, input);

    // Verificar se há zeros a esquerda
    for (int i = 0; i < strlen(in); i++) {
        // Caso seja 0, vamos mudar para uma letra qualquer (já que só pegaremos números mais em frente)
        if (in[i] == '0') in[i] = 'x';
        // Caso encontremos qualquer número (diferente de 0), parar de tirar 0
        else if (is_num(in[i])) break;
    }

    // Alocar estrutura e digitos
    bignum *new = malloc(sizeof(bignum));
    // Caso a alocação falhe
    if (new == NULL) {
        free(in);
        return NULL;
    }
    // Criar lista de dígitos
    new->digits = list_create();
    // Caso algo dê errado na criação
    if (new->digits == NULL) {
        free(in);
        free(new);
        return NULL;
    }

    // Ver se tem sinal negativo no início
    if (in[0] == '-') {
        new->negative = 1;
    } else {
        new->negative = 0;
    }

    // Colocar os dígitos
    for (int i = 0; i < strlen(in); i++) {
        // Caso seja um número
        if (is_num(in[i])) {
            // Tirar 48 (código do '0' na tabela ascii)
            int digit = in[i]-48;
            // Colocar na cauda da lista
            if (list_pushend(new->digits, &digit, sizeof(digit)) == -1) {
                // Caso algo dê errado na hora de colocar
                free(in);
                free(new);
                list_destroy(&(new->digits), &free);
                return NULL;
            }
        }
    }
    // Liberar string auxiliar
    free(in);

    // Vamos verificar se os dígitos estão vazios, para o caso especial do 0
    if (list_isempty(new->digits)) {
        // Tornar positivo
        new->negative = 0;
        // Colocar um 0 apenas
        int digit = 0;
        // Colocar na lista
        if (list_push(new->digits, &digit, sizeof(digit)) == -1) {
            // Caso dê algo errado na hora de colocar
            free(in);
            free(new);
            list_destroy(&(new->digits), &free);
            return NULL; 
        }
    }
    // Bignum prontinho
    return new;
}

// Imprime (usando a 'printfunction') o bignum. Retorna -1 em caso de falha
int bignum_print(bignum *input) {
    if (input == NULL) return -1;
    if (input->negative) printf("-");
    list_print(input->digits, &printfunction);
    return 0;
}

// Compara dois bignums. Opcionalmente ignorando os sinais (absolute = 1)
// Retorna 1 caso a > b, 0 caso a == b, -1 caso a < b
int bignum_cmp(bignum *a, bignum *b, int absolute) {
    if (a == NULL || b == NULL) return 0;
    //Caso os sinais sejam diferentes
    if ((a->negative != b->negative) && !absolute) {
        // A é positivo e B negativo, logo A maior
        if (!a->negative) return 1;
        // B é positivo e A negativo, logo B maior
        else return -1;
    //Caso os sinais sejam iguais, ou estejamos fazendo uma comparação absoluta
    } else {
        // Determinar quantidade de digitos
        int tam_a = list_size(a->digits);
        int tam_b = list_size(b->digits);

        // Essa variável irá armazenar quem é absolutamente maior
        char biggest_abs;

        // Caso tenham tamanhos diferentes
        if (tam_a != tam_b) {
            // Guardar o maior absoluto
            if (tam_a > tam_b) biggest_abs = 'a';
            else biggest_abs = 'b';

        // Caso tenham tamanhos iguais
        } else {
            // Começar do digito mais significativo (cabeça das listas)
            node *a_current = list_head(a->digits);
            node *b_current = list_head(b->digits);
            // Repetir enquanto não chegarmos no fim de alguma das listas
            while (a_current != NULL && b_current != NULL) {
                int *a_elem = node_data(a_current);
                int *b_elem = node_data(b_current);
                // Caso o numero na pos seja maior em A
                if (*a_elem > *b_elem) {
                    // A é o maior absoluto
                    biggest_abs = 'a';
                    break;
                // Caso o numero na pos seja maior em B
                } else if (*b_elem > *a_elem) {
                    // B é o maior absoluto
                    biggest_abs = 'b';
                    break;
                // Caso seja igual
                } else {
                    biggest_abs = 0;
                }
                a_current = node_next(a_current);
                b_current = node_next(b_current);
            } 
        }
        // Sinal, usaremos para inverter o retorno caso sejam negativos
        // (Sempre positivo no caso de absolute = 1)
        int signal;
        if (a->negative && !absolute) signal = -1;
        else signal = 1;

        // Caso A e B sejam diferentes
        if (biggest_abs == 'a') return 1*signal;
        else if (biggest_abs == 'b') return (-1)*signal;
        // Caso A e B sejam iguais
        else return 0;
    }
}

// Soma dois bignums, retornando um terceiro. Suporta bignums positivos ou negativos
bignum *bignum_sum(bignum *a, bignum *b) {
    // Caso algum não seja válido
    if (a == NULL || b == NULL || a->digits == NULL || b->digits == NULL) return NULL;

    // Alocar novo bignum
    bignum *sum = malloc(sizeof(bignum));
    if (sum == NULL) return NULL;

    // Criar lista de dígitos de sum
    sum->digits = list_create();
    if (sum->digits == NULL) {
        free(sum);
        return NULL;
    }

    // Caso os sinais sejam iguais, vamos somar
    if (a->negative == b->negative) {
        // O que resta para jogar na próxima casa durante a soma
        int overflow = 0;
        // Colocar o sinal correto
        sum->negative = a->negative;

        // Começar das unidades (cauda das listas)
        node *a_current = list_tail(a->digits);
        node *b_current = list_tail(b->digits);
        // Enquanto houver dígitos em a ou b, ou um overflow para colocar
        while (a_current != NULL || b_current != NULL || overflow != 0) {
            // Digit começa em 0
            int digit = 0;
            if (a_current != NULL) {
                // Pegar o dígito de A
                int *digit_a = node_data(a_current);
                // Somar ao digit
                digit += *digit_a;
                // E ir para o próximo numero da lista A
                a_current = node_prev(a_current);
            }
            if (b_current != NULL) {
                // Pegar o dígito de B
                int *digit_b = node_data(b_current);
                // Somar ao digit
                digit += *digit_b;
                // E ir para o próximo numero da lista B
                b_current = node_prev(b_current);
            }
    
            // Somar o que "subiu" da casa anterior
            digit += overflow;

            // Dividir por 10 para obter se "subiu" algo nessa soma
            overflow = digit/10;
            // Tirar módulo de 10 para tirar o que "subiu"
            digit %= 10;

            // Colocar dígito resultante na cabeça de sum
            if (list_push(sum->digits, &digit, sizeof(digit)) == -1) {
                list_destroy(&(sum->digits), &free);
                free(sum);
                return NULL;
            }
        }
    // Caso os sinais sejam diferentes, vamos subtrair
    //Iremos subtrair o maior (em modulo) pelo menor, e colocar o sinal do maior
    } else {
        // Verificar qual o maior em modulo
        int cmp = bignum_cmp(a, b, 1);

        // Minuendo (lessening), número do qual será retirado valor
        bignum *l;
        // Subtraendo (subtracting), número cujo valor será subtraido
        bignum *s;

        // Caso |A| > |B|, faremos |A| - |B| e colocaremos o sinal de A
        if (cmp > 0) {
            l = a;
            s = b;
        // Caso |B| > |A|, faremos |B| - |A| e colocaremos o sinal de B
        } else if (cmp < 0) {
            l = b;
            s = a;
        }

        // Caso |A| = |B|, teremos 0
        if (cmp == 0) {
            // Tornar positivo
            sum->negative = 0;
            // Colocar um 0 apenas
            int digit = 0;
            // Colocar 0 na lista
            if (list_push(sum->digits, &digit, sizeof(digit)) == -1) {
                // Verificar se algo errado aconteceu
                list_destroy(&(sum->digits), &free);
                free(sum);
                return NULL;
            }

        } else {


            // A -> S. B -> L
            // "Empréstimo" do algarismo seguinte na subtração
            int borrowed = 0;
            // Colocar o sinal correto
            sum->negative = l->negative;
    
            // Começar das unidades (cauda das listas)
            node *s_current = list_tail(s->digits);
            node *l_current = list_tail(l->digits);
            // Enquanto houver dígitos em S ou L
            while (s_current != NULL || l_current != NULL) {
                // Digit começa em 0
                int digit = 0;
                // Caso o S tenha algum digito na casa inicial
                if (s_current != NULL) {
                    // Pegar o dígito de S
                    int *digit_s = node_data(s_current);
                    // SUBTRAIR do digit
                    digit -= *digit_s;
                    // E ir para o próximo numero da lista S
                    s_current = node_prev(s_current);
                }
                if (l_current != NULL) {
                    // Pegar o dígito de L
                    int *digit_l = node_data(l_current);
                    // Somar ao digit
                    digit += *digit_l;
                    // E ir para o próximo numero da lista L
                    l_current = node_prev(l_current);
                }
        
                // Subtrair o "empréstimo" de digit
                digit -= borrowed;
                // Redefinir o empréstimo para 0
                borrowed = 0;
                // Caso esse algarismo tenha resultado em negativo
                if (digit < 0) {
                    // "Empresta" 1 da proxima casa
                    borrowed += 1;
                    // E coloca 10 na atual
                    digit += 10;
                }
                // Colocar dígito resultante na cabeça de sum
                if (list_push(sum->digits, &digit, sizeof(digit)) == -1) {
                    list_destroy(&(sum->digits), &free);
                    free(sum);
                    return NULL;
                }
            }
        }
    }

    return sum;
}

// Desaloca completamente um bignum
void bignum_destroy(bignum **input) {
    // Destruir a lista, passando free para liberar as ints
    list_destroy(&((*input)->digits), &free);
    // Desalocar bignum
    free(*input);
    // E colocar NULL
    *input = NULL;
}
