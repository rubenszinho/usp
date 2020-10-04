#include <stdio.h>
    int main(){
        int n, fat;
        scanf("%d", &n);
        if (n == 0){
            printf("1");
            return 0;
        }
        fat = n;
        do{
            n--;
            if(n == 0)
                n++;
            fat = n * fat;
        }
        while (n > 1);
        printf("%d", fat);

    return 0;
    }
