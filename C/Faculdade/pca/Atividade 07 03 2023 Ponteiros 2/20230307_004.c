#include <stdio.h>

int main() {
    int vet[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    int *pont_v = &vet[0], *pont_f = &vet[7], conteudo, resto;
    for(; pont_v <= pont_f; pont_v++){
        conteudo = *pont_v;
        resto = conteudo % 2;
        conteudo *= 2;
        printf("%d", conteudo);
        if(resto == 0)
            printf(" - Endereço: %d", pont_v);
        printf("\n");
    }
    return 0;
}
