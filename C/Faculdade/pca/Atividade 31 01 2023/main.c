#include <stdio.h>
#include <string.h>

int i1, i2;

void num_carac(){
    char string[100];
    printf("Digite outra frase: ");
    gets(string);

    char carac;
    printf("Digite um caractere: ");
    scanf("%c", & carac);
    i1 = strlen(string);

    char elem_var;
    int contador = 0;
    for(i2 = 0; i2 < i1; i2++){
        elem_var = string[i2];
        if(elem_var == carac)
            contador++;
    }
    printf("O numero de vezes que o caractere '%c' aparece na frase e %d.", carac, contador);
}

void apag_carac(){
    char string[100];
    printf("Digite outra frase: ");
    gets(string);

    char carac;
    printf("Digite um caractere: ");
    scanf("%c", & carac);
    i1 = strlen(string);

    char elem_var;
    for(i2 = 0; i2 < i1; i2++){
        elem_var = string[i2];
        if(elem_var == carac)
            string[i2] = ' ';
    }
    printf("%s", string);
}


int main(){
    num_carac();
    apag_carac();
    printf("\n");
    return 0;
}