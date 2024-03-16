#include <stdio.h>
#include <string.h>

int i, tam;
char nomes[][120];

void criar_lista(char strings[][120]){
    for (i = 0; i < tam; i++){
        printf("Digite um nome: ");
        gets(strings[i]);
    }
}

void impr_lista(char strings[][120]){
    for (i = 0; i < tam; i++){
        printf("%s", strings[i]);
        printf("\n");
    }
}

void elim_nome(char strings[][120], char string[]){
    char * achou;
    for (i = 0; i < tam; i++){
        achou = strstr(strings[i], string);
        if (achou != NULL) {
            int j;
            for (j = 0; j < 120; j++){
                strings[i][j] = ' ';
            }
            i = tam;
        }
    }
}

void ord_strings(char strings[][120]){
    int i1, i2;
    int lim = tam - 1;
    char temp[120], menor[120];
    for(i1 = 0; i1 < lim; i1++){
        for(i2 = i1; i2 < tam; i2++){
            if(strcmp(strings[i2], strings[i1]) < 0) {
                strcpy(temp, strings[i1]);
                strcpy(menor, strings[i2]);
                strcpy(strings[i1], menor);
                strcpy(strings[i2], temp);
            }
        }
    }
}
int main() {
    tam = 6;
    criar_lista(nomes);
    printf("\n");
    impr_lista(nomes);
    printf("\n");

    char nomes_ord_alf[tam][120];
    for (i = 0; i < tam; i++){
        strcpy(nomes_ord_alf[i], nomes[i]);
    }

    char nome[120];
    printf("Digite um dos nomes digitados: ");
    gets(nome);
    elim_nome(nomes, nome);
    printf("\n");

    ord_strings(nomes_ord_alf);
    impr_lista(nomes_ord_alf);
    return 0;
}