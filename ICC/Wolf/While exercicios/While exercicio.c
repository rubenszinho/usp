#include <stdio.h> // ESCREVER TODOS CARACTERES ATE O "s" SER PRESSIONADO
#include <conio.h>
int main(){
    char ch;
    printf("Digite um caractere(s para sair):");
    ch=getche();
    while(ch!='s'){
    printf("\nO caractere digitado e: %c",ch);
    printf("\ndigite outro caractere(s para sair):\n");
    ch=getche();
    }
printf("\nSaindo do loop\n");
getch();
}
