#include <stdio.h>
#define NULL 0

int vet1[10] = {1, 5, 7, 6, 1, 2, 2, 9, 6, 2};

int encon_valor(int *i_vet, int *f_vet){
    int *p_end = NULL, cont_geral = 0, cont_esp = 0, conteudo;
    while(i_vet <= f_vet){
        conteudo = vet1[cont_geral];
        if((conteudo == 2)) {
            printf("Valor '%d' encontrado no endereço: %d\n", *i_vet, i_vet);
            if(cont_esp == 0) {
                p_end = &vet1[cont_geral];
                cont_esp++;
            }
        }
        cont_geral++;
        i_vet++;
    }
    return *p_end;
}

int main() {
    int *i_vet1 = &vet1[0];
    int *f_vet1 = &vet1[9];

    encon_valor(i_vet1, f_vet1);
    return 0;
}