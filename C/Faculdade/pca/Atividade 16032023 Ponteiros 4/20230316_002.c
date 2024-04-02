#include <stdio.h>
#include <stdlib.h>

int main(){
    int *vetor;
    int i, j, n_lin, n_col, elem_matriz = 1;
    printf("Digite o numero de linhas da matriz: ");
    scanf("%d", &n_lin);
    printf("\nDigite o numero de colunas da matriz: ");
    scanf("%d", &n_col);
    vetor = (int *) malloc(n_lin * n_col * sizeof(int));
    for (i = 0; i < n_lin; i++){
        for (j = 0; j < n_col; j++) {
            vetor[i * n_col + j] = elem_matriz;
            elem_matriz++;
        }
    }
    printf("\n");

    int *pont_v = vetor;
    for (i = 0; i < n_lin; i++){
        for (j = 0; j < n_col; j++) {
            printf("%d ", *pont_v);
            pont_v++;
        }
        printf("\n");
    }
    printf("\n");

    for (i = 0; i < n_lin; i++){
        for (j = 0; j < n_col; j++)
            printf("%d ",vetor[i * n_col + j]);
        printf("\n");
    }

    free(vetor);
    return 0;
}