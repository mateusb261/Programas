#include <stdio.h>
#include <string.h>

int indices[3];

void carac_iguais(char string[], char *letra, int *tam){
    int i = 0, i_vet = 0, v_comp;
    char v_letra = *letra, carac_var, *pont_i = &string[0], *pont_f = &string[7];
    for(; pont_i <= pont_f; pont_i++){
        carac_var = *pont_i;
        v_comp = strcmp(carac_var, v_letra);
        if(v_comp == 0) {
            *tam += 1;
            indices[i_vet] = i;
            i_vet++;
        }
        i++;
    }
}

int main() {
    char string[] = {"amazonas"};
    char letra = 'a';
    int tam = 0;

    carac_iguais(string, &letra, &tam);
    return 0;
}
