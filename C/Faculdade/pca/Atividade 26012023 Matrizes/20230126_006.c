#include <stdio.h>

int i, j;

void gerar_matriz(int matriz[i][j]){
    int lin, col;
    for(lin = 0; lin < i; lin++){
        for(col = 0; col < j; col++) {
            printf("Digite o valor da linha %d e coluna %d: ", (lin + 1), (col + 1));
            scanf("%d", & matriz[lin][col]);
            printf("\n");
        }
    }
}

void ver_qua_mag(int matriz[i][j]){
    int soma_cons;
    int tam = i, soma_var = 0, cont_lin = 1, cont_col = 0, cont_diag_prin = 0, cont_diag_sec = 0, soma_cont;
    for(i = 0; i < tam; i++){
        for(j = 0; j < tam; j++){
            soma_var += matriz[i][j];
        }
        if(i == 0)
            soma_cons = soma_var;
        if((soma_var == soma_cons) && (i > 0))
            cont_lin++;
        else{
            if(i > 0) {
                printf("A matriz fornecida nao e um quadrado mágico.");
                return;
            }
        }
        soma_var = 0;
    }
    int tam_m = tam - 1;
    for(j = 0; j < tam; j++){
        for(i = 0; i < tam; i++)
            soma_var += matriz[i][j];
        if(soma_var == soma_cons)
            cont_col++;
        else{
            if(i == tam_m) {
                printf("A matriz fornecida nao e um quadrado mágico.");
                return;
            }
        }
        soma_var = 0;
    }
    i = 0;
    j = 0;
    soma_var = 0;
    while((i < tam) && (j < tam)) {
        soma_var += matriz[i][j];
        if ((soma_var == soma_cons) && (j == tam_m))
            cont_diag_prin++;
        else{
            if(j == tam_m) {
                printf("A matriz fornecida nao e um quadrado mágico.");
                return;
            }
        }
        i++;
        j++;
    }
    i = tam - 1;
    j = tam - 1;
    soma_var = 0;
    while((i >= 0) && (j >= 0)) {
        soma_var += matriz[i][j];
        if ((soma_var == soma_cons) && (j == 0))
            cont_diag_sec++;
        else{
            if(j == 0) {
                printf("A matriz fornecida nao e um quadrado mágico.");
                return;
            }
        }
        i--;
        j--;
    }
    soma_cont = cont_lin + cont_col + cont_diag_prin + cont_diag_sec;
    if((cont_lin == cont_col) && (cont_diag_prin == cont_diag_sec) && (soma_cont != 1)) {
        printf("A matriz fornecida e um quadrado mágico.");
    }
}

int main() {
    printf("Digite a ordem da matriz: ");
    scanf("%d", & i);
    j = i;
    printf("\n");
    int matrizA[i][j];
    gerar_matriz(matrizA);
    ver_qua_mag(matrizA);
    return 0;
}