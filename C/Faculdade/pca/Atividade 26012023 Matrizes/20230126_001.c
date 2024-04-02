#include <stdio.h>

int i = 3, j = 5;

void imp_mat(int matriz[i][j]){
    for(i = 0; i < 3; i++){
        for(j = 0; j < 5; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void soma_mat_e_imp(int matriz1[i][j], int matriz2[i][j]){
    int soma;
    for(i = 0; i < 3; i++){
        for(j = 0; j < 5; j++){
            soma = matriz1[i][j] + matriz2[i][j];
            printf("%d ", soma);
        }
        printf("\n");
    }
}

int main() {
    int matrizA[3][5] = {{1, 2, 3, 4, 5},
                         {6, 7, 8, 9, 10},
                         {11, 12, 13, 14, 15}};
    int matrizB[3][5] = {{16, 17, 18, 19, 20},
                         {21, 22, 23, 24,25},
                         {26, 27, 28, 29, 30}};
    printf("A soma das matrizes A:\n");
    imp_mat(matrizA);
    printf("\ne B:\n");
    imp_mat(matrizB);
    printf("\né:\n");
    soma_mat_e_imp(matrizA, matrizB);
    return 0;
}