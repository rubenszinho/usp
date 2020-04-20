#include <stdio.h>// x^y SEM A FUNCAO MATEMATICA
int main(){
    int x, y, z, w;
    w=1;
    scanf("%d %d", &x, &y);
    for(z=0;z<y;z++){
        w=w*x;
    }
printf("%d", w);
getch();
return 0;
}
