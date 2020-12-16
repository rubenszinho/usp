#include <stdio.h>
#include <stdlib.h>

int main(){
    int elem, n, i, j;
    int *cont_elem, *elem_sum, *v1, *v2, *comparador;
    scanf("%d", &elem);
    scanf("%d", &n);
    cont_elem=(int*)malloc(elem*sizeof(int));
    elem_sum=(int*)malloc((elem+1)*sizeof(int));
    comparador=(int*)malloc(elem*sizeof(int));
    v1=(int*)malloc(n*sizeof(int));
    v2=(int*)malloc(n*sizeof(int));
    for (i=0;i<n;i++){
        scanf("%d", &v1[i]);
        v2[i]=0;
    }
    for (i=0;i<elem;i++){
        cont_elem[i]=0;
        comparador[i]=i;
    }
    for (i=0;i<n;i++){
        for (j=0;j<elem;j++){
            if(v1[i]==comparador[j])
                cont_elem[j]++;
        }
    }
    elem_sum[0]=0;
    for (i=1;i<elem;i++){
        elem_sum[i]=cont_elem[i-1]+elem_sum[i-1];
    }
    for (i=0;i<n;i++){
      for (j=0;j<elem;j++){
        if(v1[i]==comparador[j]){
          v2[elem_sum[j]]=comparador[j];
          printf("%d %d\n", comparador[j], elem_sum[j]);
          elem_sum[j]++;
        }
      }
    }
    for (i=0;i<n;i++)
      v1[i]=v2[i];
    return 0;
}   