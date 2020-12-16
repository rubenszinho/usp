#include <stdio.h>
#include <stdlib.h>
void counting_sort(int a[], int a_digitado[], int n, int base);

int main(){
	int base, n, max_casas, d = 1;
	scanf("%d", &base);
	scanf("%d", &n);
	int *array = (int *)(malloc(n*sizeof(int)));
	int *array_aux = (int *)(malloc(n*sizeof(int)));
	for(int i = 0; i < n; i++){ 
		scanf("%d", &array[i]);
	}
	max_casas = array[0];
	for(int i = 0; i < n; i ++){
		if(array[i] > max_casas){
			max_casas = array[i];
		}
	}
	while(d <= max_casas){
		for(int i = 0; i < n; i ++){
			array_aux[i] = (array[i] / d) % base;		
		}
		counting_sort(array, array_aux, n, base);
		printf("\n");
		d *= base;
	}
	return 0;
}

void counting_sort(int a[], int a_digitado[], int n, int base){
	int *count = (int *)(malloc(base*sizeof(int)));
	int *array_sorted = (int *)(malloc(n*sizeof(int)));
	int *repeticao = (int *)(malloc(base*sizeof(int)));
	for(int i = 0; i < base; i++){
		count[i] = 0;
		repeticao[i] = 0;
	}
	for(int i = 0; i < n; i ++){
		count[a_digitado[i]] += 1;
	}
	for(int i = 1; i <= base; i ++){
		count[i] += count[i - 1]; 
	}
	for(int i = 0; i < n; i ++){
		int aux;
		if(a_digitado[i] == 0){
			aux = 0;
		} 
		else{
			aux = count[a_digitado[i]-1];
		}
		array_sorted[aux + repeticao[a_digitado[i]]] = a[i];
		repeticao[a_digitado[i]] ++;
	}
	for(int i = 0; i < n; i ++){
		a[i] = array_sorted[i];
		printf("%d ", a[i]);
	}
}