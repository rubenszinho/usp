#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct coords {
	float x, y;

} coord; //estrutura das coordenadas

float euclidiana(coord a, coord b)
{ //retorna a distância euclidiana entre dois pontos no plano

	float potencia1 = pow((a.x - b.x), 2);
	float potencia2 = pow((a.y - b.y), 2);  
	
	return sqrt(potencia1 + potencia2);
}

float modulo(float x)
{//retorna o modulo de um float

	if(x >= 0) return x;
	else return x * (-1);
}

float funcMin(float dist_esq, float dist_dir)
{//retorna o menor entre dois floats
	
	if (dist_esq > dist_dir) return dist_dir;
  	else return dist_esq;
}

void intercala(coord vet[], int c1, int f1, int c2, int f2)
{ //intercala as partes que o merge ordenou

  	coord *aux = (coord *)malloc(sizeof(coord) * (f2 - c1 + 1));

  	int i=c1; //contadores para percorrer as duas partes
  	int j=c2;
  	int k=0;

  	while(i <= f1 && j <= f2) { //enquanto um dos vetores não acaba, copia o menor para o aux
		if(vet[i].x <= vet[j].x) {
		      	aux[k++] = vet[i++];
    		}else {
     			aux[k++] = vet[j++];
    		}
  	}

  	while(i <= f1) { //copia o que sobrou na primeira metade para o vetor auxiliar
    		aux[k++] = vet[i++];
  	}

  	while(j <= f2) { //copia o que sobrou na segunda metade para o vetor auxiliar
   	 	aux[k++] = vet[j++];
  	}

  	for(int cont = c1, k=0; cont <= f2; cont++, k++)
  	{ //copia o vetor auxiliar de volta para o vetor principal
    		vet[cont] = aux[k];
  	}

  	free(aux);
}

void mergeSort(coord vet[], int c, int f)
{//com esse método, a ordenação se dá em O(nlog n)

  	if(f > c) { //não está no caso base
    		int m = (c + f) / 2;

    		mergeSort(vet, c, m);
    		mergeSort(vet, m+1, f);

    		intercala(vet, c, m, m+1, f);
  	}
	//se está no caso base não realiza nenhuma operação, pois o vetor já está ordenado
}

float forcaBruta (coord vet[], int c, int n)
{ //devido a complexidade dessa função ser O(n^2), só é utilizada no caso base da recursão
  	float min = 999999; //inicializa um minimo grande

  	for(int i=c; i<=n; i++) {
   	 	for(int j=i+1; j<=n; j++) {

      			if(euclidiana(vet[i], vet[j]) < min) { //faz a euclidiana para cada par de pontos (O(n^2)) e encontra a menor distância
        		min = euclidiana(vet[i], vet[j]);
      			}
    		}
  	}

  	return min;
}

float faixa2D(coord vet[], int c, int f, float d) {
  	float dist2;
  	int m = (c+f)/2; //encontra o meio do vetor

  	for(int i=m; i>=c; i--) { //percorre a metade esquerda do vetor do meio para o começo
		for(int j=m+1; j<=f; j++) { //percorre a metade direita do vetor do meio para o fim

    		dist2 = modulo(vet[i].x-vet[j].x);

		if(dist2 <= 2*d) { //essa parte faz com que aplique-se a euclidiana apenas para pontos localizados na 'faixa 2d'
			if(euclidiana(vet[i], vet[j]) < d) {
				d = euclidiana(vet[i], vet[j]);
    		}
    	} else return d;
		}
	}
	return d;
}

float recursivMin(coord half[], int c, int f)
{
	if((f-c) >= 1) //se está fora do caso base, ou seja, tem mais de um ponto
	{
		/* DIVISÃO */
		/* Dividindo o conjunto P em P1 e P2 */
		int halfM = (c+f)/2; //encontra o ponto médio
		
		/* CONQUISTA */
		float menorEsq = recursivMin(half, c, halfM);
		float menorDir = recursivMin(half, halfM+1, f);

		/* COMBINAÇÃO */
		float d = funcMin(menorEsq, menorDir); //d é a menor distancia entre a menor de P1 e a menor de P2

		/* devemos agora analisar os pontos que se encontram em uma faixa de tamanho 2d em torno da linha divisória */
		d = faixa2D(half, c, f, d);
		
		return d;

	}else return forcaBruta(half, c, f); //caso base, faz a força bruta
}

float div_conq(coord vet[], int n) {
	
	mergeSort(vet, 0, n-1); //ordena pela coordenada 'x' usando o merge sort, para manter a complexidade em O(nlog n)

	int c=0;
	int f=n-1;

	return recursivMin(vet, c, f);
}

int main(void)
{
	int n;
	scanf("%d", &n);

	coord vet[n]; //vetor de structs para receber as coordenadas x e y de cada ponto
	for(int i=0; i<n; i++) {
		scanf("%f %f", &vet[i].x, &vet[i].y);
	}

	float min = div_conq(vet, n);
	printf("%f\n", min);

	return 0;
}
