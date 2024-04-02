#include <stdio.h>
#include <string.h>

int i2, i1;


int numcarac(char string[], char carac[]){
    i1 = strlen(string);
    int elem_var, contador = 0;
    for(i2 = 0; i2 < i1; i2++){
        elem_var = string[i2];
        if(elem_var == carac) {
            contador++;
        }
    }
    printf("O numero de vezes que o caractere %c aparece na frase e %d vezes.", carac, contador);
    return 0;
}


int main(){

    char string3[100];
    char carac[1];
    printf("Digite outra frase: ");
    gets(string3);
    printf("Digite um caractere: ");
    gets(carac);
    numcarac(string3, carac);
    printf("\n");
    return 0;
}