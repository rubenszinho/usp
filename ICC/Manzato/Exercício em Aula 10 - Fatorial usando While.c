#include <stdio.h>
    int main(){
        int n, fat;
        scanf("%d", &n);
        if (n == 0){
            printf("1");
            return 0;
        }
        fat = n;
        while (n > 1){
            n --;
            fat = n * fat;
        }
        printf("%d", fat);

    return 0;
    }
