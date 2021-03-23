#include <stdio.h>
#include <string.h>

/* Abre um arquivo, e retorna seu ponteiro. Retorna NULL caso falhe */
FILE *abrir_arquivo(const char *nome) {
    return fopen(nome, "r");
}

/* Retorna o número de caracteres (excluindo quebras de linha) de um arquivo, -1 caso falhe */
int n_caracteres(const char *nome) {
    FILE *arquivo = abrir_arquivo(nome);
    // Checar existência
    if (!arquivo) {
        fprintf(stderr, "Erro ao abrir o arquivo '%s'\n", nome);
        return -1;
    }

    int qtde = 0;
    // Percorrer o arquivo
    for (char c = getc(arquivo); c != EOF; c = getc(arquivo)) {
        // Contabilizar todos os tipos de char, inclusive ' ' e '\n'
        qtde++;
    }
    fclose(arquivo);
    return qtde;
}

/* Retorna o número de linhas de um arquivo, -1 caso falhe */
int n_linhas(const char *nome) {
    FILE *arquivo = abrir_arquivo(nome);
    // Checar existência
    if (!arquivo) {
        fprintf(stderr, "Erro ao abrir o arquivo '%s'\n", nome);
        return -1;
    }

    int qtde = 1;
    // Percorrer o arquivo
    for (char c = getc(arquivo); c != EOF; c = getc(arquivo)) {
        // Contabilizar apenas se for \n
        if (c == '\n') qtde++;
    }
    fclose(arquivo);
    return qtde;
}

/* Retorna o número de palavras de um arquivo, -1 caso falhe */
int n_palavras(const char *nome) {
    FILE *arquivo = abrir_arquivo(nome);
    // Checar existência
    if (!arquivo) {
        fprintf(stderr, "Erro ao abrir o arquivo '%s'\n", nome);
        return -1;
    }

    // Um booleano para guardar se encontramos algum caractere além dos espaços e quebras de linha, a fim de evitar dois espaços (ou quebras de linha) consecutivos contabilizarem palavras
    int encontrei = 0;
    int qtde = 1;
    // Percorrer o arquivo
    for (char c = getc(arquivo); c != EOF; c = getc(arquivo)) {
        // Contabilizar apenas se for \n ou espaço
        if (c == '\n' || c == ' ') {
            if (encontrei) {
                qtde++;
            }
            encontrei = 0;
        } else {
            encontrei = 1;
        }
    }
    fclose(arquivo);
    return qtde;
}

/* Retorna o número ocorrências de uma palavra especificada, -1 caso falhe */
int ocorrencias_palavra(const char *nome, const char *palavra) {
    FILE *arquivo = abrir_arquivo(nome);
    // Checar existência
    if (!arquivo) {
        fprintf(stderr, "Erro ao abrir o arquivo '%s'\n", nome);
        return -1;
    }

    // Tamanho da palavra a ser buscada
    int tamanho = strlen(palavra);
    // Progresso feito na busca da palavra
    int progresso = 0;
    // Booleano pra indicar se estamos no começo de uma palavra
    int inicio_de_palavra = 1;

    int qtde = 0;

    // Percorrer o arquivo
    for (char c = getc(arquivo); c != EOF; c = getc(arquivo)) {
        // Caso o caractere bata com o caractere na palavra
        if (inicio_de_palavra && c == palavra[progresso]) {
            // Subir o progresso
            progresso++;
        // Caso cheguemos no fim da palavra ou linha
        } else if (c == ' ' || c == '\n') {
            // Caso o progresso seja igual ao tamanho da palavra, significa que encontramos ela inteira
            if (progresso == tamanho) {
                // Contabilizar palavra
                qtde++;
            }
            inicio_de_palavra = 1;
            // Reiniciar progresso
            progresso = 0;
        // Caso encontremos qualquer outro caractere
        } else {
            // Reiniciar progresso
            progresso = 0;
            // Indicar que estamos no meio de uma palavra nao buscada
            inicio_de_palavra = 0;
        }
    }
    fclose(arquivo);
    return qtde;
}

int main() {
    char arquivo[] = "Lista 7 - Parte 1.txt";

    int n1 = n_caracteres(arquivo);
    if (n1 != -1) printf("Caracteres: %d\n", n1);

    int n2 = n_linhas(arquivo);
    if (n2 != -1) printf("Linhas: %d\n", n2);

    int n3 = n_palavras(arquivo);
    if (n3 != -1) printf("Palavras: %d\n", n3);

    char palavra[] = "but";
    int n4 = ocorrencias_palavra(arquivo, palavra);
    if (n4 != -1) printf("Ocorrencias de '%s': %d\n", palavra, n4);
}
