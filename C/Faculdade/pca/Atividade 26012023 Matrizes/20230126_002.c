#include <stdio.h>

int i = 2, j = 2;

void imp_mat(int matriz[i][j]){
    for(i = 0; i < 2; i++){
        for(j = 0; j < 2; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void soma_mat_e_imp(int matriz1[i][j], int matriz2[i][j]){
    int soma;
    for(i = 0; i < 2; i++){
        for(j = 0; j < 2; j++){
            soma = matriz1[i][j] + matriz2[i][j];
            printf("%d ", soma);
        }
        printf("\n");
    }
}

int main() {
    int matrizA[2][2] = {{1, 2},
                         {3, 4}};
    int matrizB[2][2] = {{5, 6},
                         {7, 8}};
    int lin1, lin2, col1, col2;
    printf("Digite o n° de linhas da matriz 1: ");
    scanf("%d", & lin1);
    printf("Digite o n° de colunas da matriz 1: ");
    scanf("%d", & col1);
    printf("Digite o n° de linhas da matriz 2: ");
    scanf("%d", & lin2);
    printf("Digite o n° de colunas da matriz 2: ");
    scanf("%d", & col2);
    if(lin1 != lin2 || col1 != col2)
        printf("As matrizes nao tem a mesma ordem. \n");
    else {
        printf("A soma das matrizes A:\n");
        imp_mat(matrizA);
        printf("\ne B:\n");
        imp_mat(matrizB);
        printf("\né:\n");
        soma_mat_e_imp(matrizA, matrizB);
    }
    return 0;
}