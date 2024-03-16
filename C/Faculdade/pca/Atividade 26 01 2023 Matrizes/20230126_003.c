#include <stdio.h>

int i = 3, j = 3;

void gerar_matriz(int matriz[i][j]){
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++) {
            printf("Digite o valor da linha %d e coluna %d: ", (i + 1), (j + 1));
            scanf("%d", & matriz[i][j]);
            printf("\n");
        }
    }
}


void imp_mat(int matriz[i][j]){
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void mult_mat_e_imp(int matriz1[i][j], int escalar){
    int prod;
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            prod = escalar * matriz1[i][j];
            printf("%d ", prod);
        }
        printf("\n");
    }
}

int main() {
    int matrizA[3][3], escalar;
    gerar_matriz(matrizA);
    printf("Digite o valor do escalar a multiplicar a matriz: ");
    scanf("%d", & escalar);
    printf("\n");
    printf("A multiplicaçao da matriz A:\n");
    imp_mat(matrizA);
    printf("\npor %d é a matriz:\n", escalar);
    mult_mat_e_imp(matrizA, escalar);
    return 0;
}