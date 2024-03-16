#include <stdio.h>
#include <stdlib.h>

int main(){
    double *matriz1, *matriz2, elem_matriz1 = 1.1, elem_matriz2 = 1.2;
    int i, j, n_lin1, n_col1, n_lin2, n_col2;

    printf("Digite o numero de linhas da matriz 1: ");
    scanf("%d", &n_lin1);
    printf("Digite o numero de colunas da matriz 1: ");
    scanf("%d", &n_col1);

    printf("Digite o numero de linhas da matriz 2: ");
    scanf("%d", &n_lin2);
    printf("Digite o numero de colunas da matriz 2: ");
    scanf("%d", &n_col2);

    matriz1 = (double *) malloc(n_lin1 * n_col1 * sizeof(double));
    for (i = 0; i < n_lin1; i++){
        for (j = 0; j < n_col1; j++) {
            matriz1[i * n_col1 + j] = elem_matriz1;
            elem_matriz1++;
        }
    }

    matriz2 = (double *) malloc(n_lin2 * n_col2 * sizeof(double));
    for (i = 0; i < n_lin2; i++){
        for (j = 0; j < n_col2; j++) {
            matriz2[i * n_col2 + j] = elem_matriz2;
            elem_matriz2++;
        }
    }

    printf("A soma das matrizes formadas e: \n");
    i = 0;
    double soma;
    for(; i < n_lin1; i++){
        for(j = 0; j < n_col2; j++){
            soma = *matriz1 + *matriz2;
            printf("%.1f ", soma);
            matriz1++;
            matriz2++;
        }
        printf("\n");
    }
    return 0;
}