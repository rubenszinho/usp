#include <stdio.h>
int main (){
    int C;
    float A, B, result;
    scanf("%f", &A);
    scanf("%f", &B);
    scanf("%d", &C);
    if(C == 1){
        result = A + B;
        printf("%.1f", result);
    }
    else if (C == 2){
        result = A - B;
        printf("%.1f", result);
    }
    else if (C == 3){
        result = A * B;
        printf("%.1f", result);
    }
    else if (C == 4){
        if(B == 0){
            printf("-1");
        }
        else{
            result = A / B;
            printf("%.1f", result);
        }
    }
    else if(C != 1 && C != 2 && C != 3 && C != 4)
        printf("-1");
return 0;
}
