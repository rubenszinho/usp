#include <stdio.h>
int main() {
    int matriz[10][10], transposta[10][10], l, c, i, j;
    scanf("%d", &l);
    scanf("%d", &c);
    for (i = 0; i < l; ++i)
        for (j = 0; j < c; ++j) {
            scanf("%d", &matriz[i][j]);
        }
    for (i = 0; i < l; ++i)
        for (j = 0; j < c; ++j) {
            transposta[j][i] = matriz[i][j];
        }

    for (i = 0; i < c; ++i)
        for (j = 0; j < l; ++j) {
            printf("%d ", transposta[i][j]);
            if (j == l - 1)
                printf("\n");
        }
    return 0;
}
