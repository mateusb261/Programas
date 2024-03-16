#include <stdio.h>

int i = 5, j = 5;

void gerar_matriz(int matriz[i][j]){
    for(i = 0; i < 5; i++){
        for(j = 0; j < 5; j++) {
            printf("Digite o valor da linha %d e coluna %d: ", (i + 1), (j + 1));
            scanf("%d", & matriz[i][j]);
            printf("\n");
        }
    }
}

void imp_diag_prin(int matriz[i][j]){
    int lin = 0, col = 0;
    printf("Os numeros da diagonal principal da matriz sao: ");
    while(lin < i && col < j){
        printf("%d ", matriz[lin][col]);
        lin++;
        col++;
    }
    printf("\n");
}

void imp_diag_sec(int matriz[i][j]){
    int lin = 0, col = 4;
    printf("Os numeros da diagonal secundaria da matriz sao: ");
    while(lin < i && col >= 0){
        printf("%d ", matriz[lin][col]);
        lin++;
        col--;
    }
    printf("\n");
}

void imp_som_lin4(int matriz[i][j]){
    int lin4 = 3, col, soma = 0;
    for(col = 0; col < j; col++){
        soma += matriz[lin4][col];
    }
    printf("A soma dos numeros da linha 4 da matriz e: %d\n", soma);
}

void imp_som_col2(int matriz[i][j]){
    int lin, col = 1, soma = 0;
    for(lin = 0; lin < i; lin++){
        soma += matriz[lin][col];
    }
    printf("A soma dos numeros da coluna 2 da matriz e: %d\n", soma);
}

void imp_som_tudo_exc_diag_prin(int matriz[i][j]){
    int lin, col, soma = 0;
    for(lin = 0; lin < i; lin++){
        for(col = 0; col < j; col++){
            if(lin != col) {
                soma += matriz[lin][col];
            }
        }
    }
    printf("A soma de todos os numeros da matriz, exceto os da diagonal principal, e: %d", soma);
}

int main() {
    int matrizA[5][5];
    gerar_matriz(matrizA);
    imp_diag_prin(matrizA);
    imp_diag_sec(matrizA);
    imp_som_lin4(matrizA);
    imp_som_col2(matrizA);
    imp_som_tudo_exc_diag_prin(matrizA);
    return 0;
}