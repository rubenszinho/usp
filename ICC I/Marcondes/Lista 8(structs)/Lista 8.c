#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct aniversariante {
  char nome[50];
  int dia;
  int mes;
  int ano;
  int removido; // removido = 0: não foi removido, removido = 1: foi removido
  
} niver;

// Abre um arquivo, e retorna seu ponteiro. Retorna NULL caso falhe 
FILE *abrir_arquivo(const char *nome) {
  return fopen(nome, "w+b");
}

FILE *abrir_arquivo_w(const char *arquivo_vet) {
  return fopen(arquivo_vet, "w");
}

int main() {
    char registro_niver[] = "Lista 8 - Registro Aniversariante.dat";
    char registro_niver_txt[] = "Lista 8 - Registro Aniversariante.csv";
    FILE *registro_niverp = abrir_arquivo(registro_niver);
    if(registro_niverp == NULL) {
        printf("Erro ao abrir registro_niver.\n");
        exit(1);
    }    
    int x; // Tipo de operacao
    int numero_aniversariante = 1; // Index da struct
    int mes_buscado;
    char aniversariante_remov[50];
    niver leitura;
    niver *lista = (niver *) malloc (sizeof(niver)*1); // Declarando vetor lista que servirá para fazer o percurso na struct a partir de um vetor
    while(1){
        printf("Menu:\nBem vindo a tela inicial de registro de aniversariantes, digite o numero referente a uma das opcoes abaixo para escolhe-las (se quiser  encerrar a sessao digite -1)\n\n");
        printf("1.Cadastrar\n2.Buscar aniversariante pelo mes\n3.Remover aniversariante\n");
        scanf("%d", &x);
        int flag = 1; // Sinalizador para saber se um elemento buscado foi encontrado ou não
        if (x == -1) break; // Operacao igual à -1 é finalizam as operacoes
        system("cls");
        switch (x){
            case 1: // Cadastrar
              // Alocando dinâmicamente a struct para efetuar registro sem vazão de memoria
              lista = (niver *) realloc (lista, numero_aniversariante * (sizeof(niver)));
              printf("Cadastro:\nRegistre o aniversariante informando o nome e a data de nascimento\n\n");
              printf("Nome:\n");
              scanf("%s", lista[numero_aniversariante - 1].nome);
              printf("Data de nascimento (dd/mm/aaaa):\n");
              scanf("%d/%d/%d;", &lista[numero_aniversariante - 1].dia, &lista[numero_aniversariante - 1].mes, &lista[numero_aniversariante - 1].ano);
              lista[numero_aniversariante - 1].removido = 0;
              fwrite (&lista[numero_aniversariante - 1], sizeof(niver), 1, registro_niverp);
              numero_aniversariante ++;
              printf("Aperte qualquer tecla para voltar para o Menu\n");
              getch();
              system("cls");
            break;

            case 2: //Buscar
              printf("Digite o mes desejado para buscar seus respectivos aniversariantes\n");
              scanf("%d", &mes_buscado);
              fseek(registro_niverp, 0, SEEK_SET);

              // lendo o que ja foi escrito ate achar o mes inserido igual ao mes da struct e qu também não tenha sido removido
              while(fread(&leitura, sizeof(niver), 1, registro_niverp) > 0){
                if(mes_buscado == leitura.mes && leitura.removido == 0){
                  printf("Nome:%s\n", leitura.nome);
                  printf("Data de nascimento:%d/%d/%d\n", leitura.dia, leitura.mes, leitura.ano);
                  flag = 0; // Flag so se manterá 1 se nunca tiver sido 0
                }
              }
              if (flag == 1) printf("Ninguem deste mes encontrado\n");
              printf("Aperte qualquer tecla para voltar para o Menu\n");
              getch();
              system("cls"); 
            break;

            // Remocao por Desempilhamento: se for remover 2 aniversariantes com nomes iguais, esta funcao sempre removerá a que foi registrada primeiro
            case 3:
              printf("Digite o nome do aniversariante que voce deseja remover o cadastro\n");
              scanf("%s", aniversariante_remov);
              int contador = 0;
              fseek(registro_niverp, 0, SEEK_SET);
              while(fread(&leitura, sizeof(niver), 1, registro_niverp) > 0){
                if(strcmp(leitura.nome, aniversariante_remov) == 0 && leitura.removido == 0){// Remover aquele com string semelhante que não tenha sido removido
                  leitura.removido = 1; // Alterando o estado de remocao à ser escrito
                  fseek(registro_niverp, (contador)*sizeof(niver), SEEK_SET); // Salvando o cursor para pegar o calmpo leitura.removido do aniversariante desejado
                  fwrite (&leitura, sizeof(niver), 1, registro_niverp); // Escrevendo o estado de remocao assumido 2 linhas atrás
                  printf("Aniversariante '%s' removido com sucesso\n", aniversariante_remov);
                  flag = 0; // Flag so se manterá 1 se nunca tiver sido 0
                  break;
                }
                contador++;
              }
              if(flag == 1) printf("Aniversariante '%s' nao encontrado\n", aniversariante_remov);
              printf("Aperte qualquer tecla para voltar para o Menu\n");
              getch();
              system("cls");
            break;

            default:
                printf ("Valor de operacao invalido!\n");
                printf("Aperte qualquer tecla para voltar para o Menu\n");
                getch();
                system("cls");
        }
    }
    fseek(registro_niverp, 0, SEEK_SET);
    FILE *registro_niver_txtp = abrir_arquivo_w(registro_niver_txt); // Arquivo CSV
    
    // Lendo todo o arquivo binário e copiando para o CSV aos poucos
    while(fread(&leitura, sizeof(niver), 1, registro_niverp) > 0) {
      if(leitura.removido == 0){
        if(registro_niver_txtp == NULL) {
            printf("Erro ao abrir registro_niver_txt.\n");
            exit(1);
        }
        fprintf(registro_niver_txtp, "Nome:%s\n", leitura.nome);
        fprintf(registro_niver_txtp, "Data de nascimento: %d/%d/%d\n", leitura.dia, leitura.mes, leitura.ano);
        fprintf(registro_niver_txtp, "=======================\n");
      }
    }
    fclose(registro_niver_txtp);
    fclose(registro_niverp);
    return 0;        
}