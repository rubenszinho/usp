#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <limits.h>

/* FUNCOES AUXILIARES*/
// Abre um arquivo, e retorna seu ponteiro. Retorna NULL caso falhe 
FILE *abrir_arquivo_wb(const char *arquivo_vet) {
  return fopen(arquivo_vet, "wb");
}

FILE *abrir_arquivo_rb(const char *arquivo_vet) {
  return fopen(arquivo_vet, "rb");
}

//Ordenando vetores
void insertion_sort(int v[], int tam){
  int i, j, aux;
  for (i = 0; i < tam; i++){
    aux = v[i];
    j = i - 1;
    v[i] = aux;
    while (aux < v[j]){
      v[j + 1] = v[j];
      j--;
    }
    v[j + 1] = aux;
   }

  // Impressão do vetor ordenado
  printf("Vetor em ordem:\n");
  for(int i = 0; i < tam; i++) {
    printf("%d ", v[i]);
  }
  printf("\n");
}


// Gerando vetores aleatoriamente preenchidos de tamanho n
void gera_vetor(int tam, int v[]){

  // Garantir que o mesmo vetor nao seja gerado (muda a seed)
  srand(time(NULL));

  // Preenche o vetor com valores aleatórios
  printf("Vetor randomico:\n");
  for(int i = 0; i < tam; i++) {
    v[i] = rand() % 100;
    printf("%d ", v[i]);
  }
  printf("\n");
}


/*Funcao 1) Gerar um vetor de inteiros de tamanho n preenchido 
com valores aleatórios (use o comando rand do math.h). 
Ordenar o vetor e salvar o vetor ordenado em um arquivo binário.*/
void funcao_1(int tam, const char *arquivo_vet) {
  int vet[tam];

  printf("Funcao 1\n");

  // Gerando vetores
  gera_vetor(tam, vet);

  // Ordenando vetor usando variável auxiliar (O(n²))
  insertion_sort(vet, tam);

  // Transcrevendo o vetor ordenado gerado
  FILE *arquivop_vet = abrir_arquivo_wb(arquivo_vet);
  if(arquivop_vet == NULL) {
    printf("Erro ao abrir arquivo_vet.\n");
    exit(1);
  }
  fwrite (vet, sizeof(int), tam, arquivop_vet);
  fclose(arquivop_vet);
 
  // Lendo o conteudo para conferir a transcircao
  arquivop_vet = abrir_arquivo_rb(arquivo_vet);
  int vet_aux[tam];
  printf("Conteudo do arquivo binario ordenado:\n");
  while(feof(arquivop_vet) == 0) {
    fread(vet_aux, sizeof(int), tam, arquivop_vet);
  }
  for(int i = 0; i < tam; i ++) {
    printf("%d ", vet_aux[i]);
  }
  printf("\n\n");
  fclose(arquivop_vet);
}


/*Função 2) Dado dois arquivos binários, cada um com seus vetores 
de inteiros ordenados, gerar um terceiro arquivo binário com o 
conteúdo ordenado dos dois arquivos.
*Arquivo 1: [1, 4, 9, 10, 53, 88]
*Arquivo 2: [0, 5, 7, 15, 37, 43]
*Arquivo 3: [0, 1, 4, 5, 7, 9, 10, 15, 37, 43, 53, 88].*/
void funcao_2(const char *arquivo_1, const char *arquivo_2, const char *arquivo_3) {
  printf("Funcao 2\n");
  int tam = 6; // Tamanho predefinido pelo exercicio

  // Declarando vetor 1 predefinido pelo exercicio
  int vet_arq1[6] = { 1, 4, 9, 10, 53, 88 };
  FILE *arquivop_1 = abrir_arquivo_wb(arquivo_1);
  if(arquivop_1 == NULL) {
    printf("Erro ao abrir arquivo_1.\n");
    exit(1);
  }

  // Transcrevendo o vetor dado no arquivo binário 1
  fwrite(vet_arq1, sizeof(int), tam, arquivop_1);
  fclose(arquivop_1);

  // Abrindo para leitura para imprimir o conteudo do arquivo binario, e ver se foi corretamente transcrito
  arquivop_1 = abrir_arquivo_rb(arquivo_1);
  if(arquivop_1 == NULL) {
    printf("Erro ao abrir arquivo_1.\n");
    exit(1);
  }
  int vet_aux1[tam]; // Usando auxiliar para pegar o conteudo
  printf("Arquivo 1:\n");
  while(feof(arquivop_1) == 0) {
    fread(vet_aux1, sizeof(int), tam, arquivop_1);
  }
  for(int i = 0; i < tam; i ++) {
    printf("%d ", vet_aux1[i]);
  }
  printf("\n");
  fclose(arquivop_1);
  
  // Declarando vetor 2 predefinido pelo exercicio
  int vet_arq2[6] = { 0, 5, 7, 15, 37, 43 };
  FILE *arquivop_2 = abrir_arquivo_wb(arquivo_2);
  if(arquivop_2 == NULL) {
    printf("Erro ao abrir arquivo_2.\n");
    exit(1);
  }

  // Transcrevendo o vetor dado no arquivo binário 2
  fwrite(vet_arq2, sizeof(int), tam, arquivop_2);
  fclose(arquivop_2);

  // Abrindo para leitra para pegar o conteudo do arquivo binario, e ver se foi corretamente transcrito
  arquivop_2 = abrir_arquivo_rb(arquivo_2);
  if(arquivop_2 == NULL) {
    printf("Erro ao abrir arquivo_2.\n");
    exit(1);
  }
  int vet_aux2[tam];
  printf("Arquivo 2:\n");
  while(feof(arquivop_2) == 0) {
    fread(vet_aux2, sizeof(int), tam, arquivop_1);
  }
  for(int i = 0; i < tam; i ++) {
    printf("%d ", vet_aux2[i]);
  }
  printf("\n");
  fclose(arquivop_2);
  
  // Por fim, lendo o arquivo_1 e o arquivo_2 para copiá-los em ordem para o arquivo_3
  arquivop_1 = abrir_arquivo_rb(arquivo_1);
  arquivop_2 = abrir_arquivo_rb(arquivo_2);
  FILE *arquivop_3 = abrir_arquivo_wb(arquivo_3);
  if(arquivop_1 == NULL ) {
    printf("Erro ao abrir arquivo_1.\n");
    exit(1);
  }
  if(arquivop_2 == NULL) {
    printf("Erro ao abrir arquivo_2.\n");
    exit(1);
  }
  if(arquivop_3 == NULL) {
    printf("Erro ao abrir arquivo_3.\n");
    exit(1);
  }
  int cursor_1 = 0;
  int cursor_2 = 0;
  int cursor_3 = 0;
  int aux_1, aux_2;

  while(1) {

    // Salvar os cursores de cada ciclo
    fseek(arquivop_1, cursor_1*sizeof(int), SEEK_SET); 
    fseek(arquivop_2, cursor_2*sizeof(int), SEEK_SET);
    fseek(arquivop_3, cursor_3*sizeof(int), SEEK_SET);

    // Indo até o fim do vetor 
    if(cursor_1 < tam) { 
      fread(&aux_1, sizeof(int), 1, arquivop_1);
    }

    // Depois que percorrer todo o vetor dentro do arquivo binário, aumentar muito o valor da variavel comparativa para não pegar os lixos subsequentes
    else aux_1 = INT_MAX;

    if(cursor_2 < tam) {
      fread(&aux_2, sizeof(int), 1, arquivop_2); // Salvando o conteudo numa variavel auxiliar da respectiva posicao
    }
    else aux_2 = INT_MAX; 

    // Comparando o conteudo nas respectivas posicoes 
    if(aux_1 < aux_2) {
      fwrite(&aux_1, sizeof(int), 1, arquivop_3); // Transcrevendo o menor no arquivo 3 (mantendo a ordenacao crescente)
      cursor_1++; // Aumentar sempre a posicao para controlar o cursor no proximo loop
    }
    else if(aux_2 < aux_1) {
      fwrite(&aux_2, sizeof(int), 1, arquivop_3);
      cursor_2++;
    }
    else break; // Os arquivos binarios 1 e 2 já foram percorridos e transcritos
    cursor_3++;
  }
  fclose(arquivop_1);
  fclose(arquivop_2);
  fclose(arquivop_3);

  // Lendo e imprimindo arquivo 3
  printf("Arquivo 3:\n");
  arquivop_3 = abrir_arquivo_rb(arquivo_3);
  if(arquivop_3 == NULL) {
    printf("Erro ao abrir arquivo_3.\n");
    exit(1);
  }
  fseek(arquivop_3, 0, SEEK_SET);
  int vet_aux3[2*tam];
  while(feof(arquivop_3) == 0) { // Resetando o cursor, pois o arquivo ja foi percorrido
    fread(vet_aux3, sizeof(int), 2*tam, arquivop_3);
  }
  for(int i = 0; i < 2*tam; i ++) {
    printf("%d ", vet_aux3[i]);
  }
  printf("\n");
  fclose(arquivop_3);
}


int main() {
  //FUNCAO 1
  int n;
  scanf("%d", &n);
  char arquivo_vet[] = "Lista 7 - Parte 2 - arquivo_vet.dat";
  funcao_1(n, arquivo_vet);

  //FUNCAO 2
  char arquivo_1[] = "Lista 7 - Parte 2 - arquivo_1.dat";
  char arquivo_2[] = "Lista 7 - Parte 2 - arquivo_2.dat";
  char arquivo_3[] = "Lista 7 - Parte 2 - arquivo_3.dat";
  funcao_2(arquivo_1, arquivo_2, arquivo_3);

  return 0;
}