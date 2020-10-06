#include <stdio.h>
    int main(){
        int n1 = 0, n2 = 1, x1, x2;
        for (int i = 0; i < 16; i++){
            x2 = n1 + n2;
            x1 = n2;
            n2 = x2 - n1;
            n1 = x2;
            printf("%d + %d = %d\n", n1, n2, x2);
        }
    return 0;
    }