#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

//estrutura que armazenará os dois primeiros dados da linha do arquivo em a e b, para excluir a espécie.
struct dados{
  double a;
  double b;
  char *especie;
  int grupo;
};

typedef struct dados dados_t;

//declaração das funções
dados_t *pegadados(FILE *arq);
dados_t *repr(dados_t *data, int k);
double euclidiana(dados_t flor, dados_t repr);
void cria_grupos(dados_t *data, dados_t *vet, int k);
void atualiza_repr(dados_t *data, dados_t *nvrep, int k);
void imprime_res(dados_t *data, dados_t *vet, int k);

//**********************************execução da main*************************************************************

int main(void) {
  //abre o arquivo para leitura
  FILE *arq = fopen("iris_petalas.csv", "r");

  //sai do programa se não conseguir abrir o arquivo
  if(arq == NULL) {
    printf("Erro ao abrir o arquivo.\n");
    exit(1);
  }

  //chama as funções 
  int k, x;
  scanf("%d", &k);
  scanf("%d", &x);
  dados_t *novos_rep = (dados_t *)malloc(sizeof(dados_t)*k);

  dados_t *data = pegadados(arq);
  //printf("TESTE: PRIMEIROS REPRESENTANTES\n");
  dados_t *representantes = repr(data, k);
  cria_grupos(data, representantes, k);
  
  for(int i = 0; i < x; i ++) {
    //printf("%da atualização de representante:\n", i+1);
    atualiza_repr(data, novos_rep, k);
    cria_grupos(data, novos_rep, k);

  }
  imprime_res(data, novos_rep, k);
  fclose(arq);

  return 0;
}

//definições das funções criadas:

//armazenar os dados da tabela
dados_t *pegadados(FILE *arq) {
  //cria um vetor de structs, para guardar todos os dados do arquivo fonte
  dados_t *data = (dados_t *)malloc(sizeof(dados_t) * 150);
  
  //aloca espaço para a string "especie" para cada struct
  for(int i=0; i<150; i++) {
    data[i].especie = (char *)malloc(sizeof(char)*15);
  }
  
  //recebe os dados do arquivo e guarda nos campos da struct, além de inicializar os campos de "grupo" com -1 para controle
  for(int i=0; i < 150; i++){
    fscanf(arq, "%lf,%lf,%s\n", &data[i].a, &data[i].b, data[i].especie);
    data[i].grupo = -1;
    //printf("TESTE: data %d = %.1lf, %.1lf, %s\n", i, data[i].a, data[i].b, data[i].especie);
  }
 
  //retorna esse vetor de structs
  return data;
}

//escolher representantes aleatoriamente
dados_t *repr(dados_t *data, int k) {
  srand(time(NULL));
  int randline; //sorteia uma linha pra pegar uma amostra

  dados_t *vet = (dados_t *)malloc(sizeof(dados_t)*k);
  
  int *aux = malloc(sizeof(int)*k);

  for(int i = 0; i < k; i++) {
    randline = rand() % 150;
    aux[i] = randline;
    
    //para caso rand sorteie um mesmo valor, decrementa o i, para sortear novamente
    for(int j = 0; j < i; j++) {
      if(randline == aux[j]) {
        i--;
      }
    }

      //vet também é um vetor de structs, porém de tamanho "k", então cada ponteiro de vet aponta para uma struct de data diferente, escolhida aleatoriamente
      vet[i].a = data[randline].a;
      vet[i].b = data[randline].b;
      vet[i].grupo = i;

      //Teste
      //printf("Representante %d: %.1lf, %.1lf\n", i, vet[i].a, vet[i].b);
  }

  //retorna um vetor de tamanho k, com as k amostras sorteadas para criação dos grupos.
  return vet;
}

//retorna a distancia euclidiana de dois pontos
double euclidiana(dados_t flor, dados_t repr) {
  return sqrt(pow((flor.a - repr.a), 2) + pow((flor.b - repr.b), 2));
}

//cria os grupos através dos calculos das distâncias euclidianas
void cria_grupos(dados_t *data, dados_t *vet, int k) {
  double menor_1, menor_2;
  double menor_euc, menor_aux;
  int j;

  for (int i = 0; i < 150; i++) {
      j = 0;
      //utiliza as médias entre as distâncias euclidianas para comparar
      menor_euc = euclidiana(data[i], vet[j]);
      data[i].grupo = vet[j].grupo; //inicializei no primeiro grupo antes do laco, pq caso nao seja menor vai mater-se
        while(j < k){ //percorrendo representantes
          j++;
          menor_aux = euclidiana(data[i], vet[j]);
          
          if(menor_aux < menor_euc ){
            menor_euc = menor_aux;
            data[i].grupo = vet[j].grupo; 
          }
      }
  }
}

void atualiza_repr(dados_t *data, dados_t *nvrep, int k) {
  double soma_a = 0, soma_b = 0;
  double media_a, media_b;
  int cont = 0; //tamanho de cada grupo
  for(int i=0; i<k; i++) {
    for(int j=0; j<150; j++) {
      if(data[j].grupo == i) {
        soma_a += data[j].a;
        soma_b += data[j].b;
        cont++;
      }
    }
    if(cont == 0) continue;
    media_a = soma_a / cont;
    media_b = soma_b / cont;
    soma_a = 0; 
    soma_b = 0;
    cont = 0;
    nvrep[i].a = media_a;
    nvrep[i].b = media_b;
    nvrep[i].grupo = i;
    nvrep[i].especie = "vazio";

    //printf("Teste %d: a = %.1lf, b = %.1lf\n", i, nvrep[i].a, nvrep[i].b);
  }
}

//imprime os resultados no novo arquivo, além dos novos representantes
void imprime_res(dados_t *data, dados_t *vet, int k) {
  FILE *res = fopen("arquivo_result", "w");
  if(res == NULL) {
    printf("Falhou ao tentar abrir o arquivo para escrita.\n");
    exit(1);
  }

  for(int i=0; i<150; i++) {
      fprintf(res, "%.1lf, %.1lf, %s || Grupo: %i\n", data[i].a, data[i].b, data[i].especie, data[i].grupo);
  }
  char nvs[] = "\n\nNovos representantes:\n";
  char vazio[] = "Vazio\n";
  fprintf(res, "%s", nvs);

  for(int i=0; i<k; i++) {
    if(vet[i].a != 0 && vet[i].b != 0)
      fprintf(res, "Grupo %d: %.1lf, %.1lf\n", i, vet[i].a, vet[i].b);
    else {
      fprintf(res, "Grupo %d: %s", i, vazio);
    }
  }

  fclose(res);
}