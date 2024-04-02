#include <stdio.h>

int i1, j1, i2, j2, i3, j3;

int mult_matrizes(int matriz1[i1][j1], int matriz2[i2][j2], int matriz3[i3][j3], int i1, int j1, int i2, int j2){
    if(j1 != i2){
        return 0;
    }
    else{
        int lin_m_res = i3 - 1;
        int col_m_res = j3 - 1;
        int soma_var = 0;
        int i3 = 0, j3 = 0;
        i1 = 0;
        j1 = i1;
        i2 = i1;
        j2 = i1;
        while(i3 <= lin_m_res){
            while(j3 <= col_m_res){
                while(j1 < col_m_res){
                    soma_var += matriz1[i1][j1] * matriz2[i2][j2];
                    j1++;
                    i2++;
                }
                j1 = 0;
                i2 = 0;
                j2++;
                matriz3[i3][j3] = soma_var;
                soma_var = 0;
                j3++;
            }
            i1++;
            j2 = 0;
            j3 = 0;
            i3++;
        }
        return 1;
    }
}

int main() {
    printf("Digite o n° de linhas da matriz 1: ");
    scanf("%d", & i1);
    printf("\n");
    printf("Digite o n° de colunas da matriz 1: ");
    scanf("%d", & j1);
    printf("\n");
    printf("Digite o n° de linhas da matriz 2: ");
    scanf("%d", & i2);
    printf("\n");
    printf("Digite o n° de colunas da matriz 2: ");
    scanf("%d", & j2);
    printf("\n");
    i3 = i1;
    j3 = j2;
    int matriz1[i1][j1], matriz2[i2][j2], matriz3[i3][j3];
    int lin, col;
    for(lin = 0; lin < i1; lin++) {
        for (col = 0; col < j1; col++) {
            printf("Digite o valor da linha %d e coluna %d da matriz 1: ", (lin + 1), (col + 1));
            scanf("%d", & matriz1[lin][col]);
            printf("\n");
        }
    }
    for(lin = 0; lin < i2; lin++) {
        for (col = 0; col < j2; col++) {
            printf("Digite o valor da linha %d e coluna %d da matriz 2: ", (lin + 1), (col + 1));
            scanf("%d", & matriz2[lin][col]);
            printf("\n");
        }
    }
    int resposta = mult_matrizes(matriz1, matriz2, matriz3, i1, j1, i2, j2);
    if(resposta == 0){
        printf("As matrizes não podem ser multiplicadas.");
    }
    else{
        printf("As matrizes podem ser multiplicadas.");
    }
    return 0;
}